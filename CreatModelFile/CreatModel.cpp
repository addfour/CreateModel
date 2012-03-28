#include "CreatModel.h"
#include <QtGui/QWidget>
#include <QtCore/QDir>
#include <QtGui/QFont>
#include <QtGui/QItemSelectionModel>
#include <QtGui/QFileDialog>
#include <QtCore/QFileInfo>
#include <QtCore/QTextStream>
#include <QtXml/QDomNode>
#include <QtGui/QMessageBox>
#include <QtGui/QCloseEvent>


CreatModel::CreatModel(QWidget* parent)
: QDialog(parent), m_flag(0), m_infos(new QStandardItemModel),m_flagName("")
{ 
	//this->setFixedSize(572, 554);
	this->resize(572, 580);
	QPixmap iconImg(QDir::currentPath() +"/image/model.png");
	QIcon icon(iconImg);
	this->setWindowIcon(icon);
	this->setWindowTitle("ģ�͹����װ����");

	//menuBar = new QMenuBar(this);
	//QMenu* menuStart = menuBar->addMenu("��ʼ");
	//QAction* actionNew = menuStart->addAction("�½�");
	//actionNew->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_N));
	//QAction* actionOpen = menuStart->addAction("��");
	//actionOpen->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));
	//QAction* actionSave = menuStart->addAction("����");
	//actionSave->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_S));
	//QAction* actionSaveAs = menuStart->addAction("���Ϊ...");
	//QAction* actionExit = menuStart->addAction("�˳�(Exit)");
	//QMenu* menuHelp = menuBar->addMenu("����");

	//connect(actionSave, SIGNAL(triggered()), this, SLOT(OnSave()));
	//connect(actionSaveAs, SIGNAL(triggered()), this, SLOT(OnSaveAs()));
	//connect(actionNew, SIGNAL(triggered()), this, SLOT(OnNew()));
	//connect(actionOpen, SIGNAL(triggered()), this, SLOT(OnOpen()));
	//connect(actionExit, SIGNAL(triggered()), this, SLOT(OnQuit()));

	btn_new = new QPushButton(this);
	btn_new->setGeometry(QRect(19, 10, 50, 20));
	btn_new->setIcon(QIcon("image/new.png"));
	btn_new->setText("�½�");
	btn_new->setFlat(true);

	btn_open = new QPushButton(this);
	btn_open->setGeometry(QRect(90, 10, 50, 20));
	btn_open->setIcon(QIcon("image/open.png"));
	btn_open->setText("��");
	btn_open->setFlat(true);

	btn_save = new QPushButton(this);
	btn_save->setGeometry(QRect(160, 10, 50, 20));
	btn_save->setIcon(QIcon("image/save.png"));
	btn_save->setText("����");
	btn_save->setFlat(true);

	btn_saveAs = new QPushButton(this);
	btn_saveAs->setGeometry(QRect(230, 10, 65, 20));
	btn_saveAs->setIcon(QIcon("image/saveAs.png"));
	btn_saveAs->setText("���Ϊ");
	btn_saveAs->setFlat(true);

	lb_filePath = new QLabel(this);
	lb_filePath->setGeometry(QRect(20, 29,520 , 36));

	connect(btn_save, SIGNAL(clicked()), this, SLOT(OnSave()));
	connect(btn_saveAs, SIGNAL(clicked()), this, SLOT(OnSaveAs()));
	connect(btn_new, SIGNAL(clicked()), this, SLOT(OnNew()));
	connect(btn_open, SIGNAL(clicked()), this, SLOT(OnOpen()));
	
	gb_modelInfo = new QGroupBox(this);
	gb_modelInfo->setGeometry(QRect(9, 70, 551, 226));

	lb_modelName = new QLabel(gb_modelInfo);
	lb_modelName->setGeometry(QRect(10, 22, 60, 16));
	ledit_modelName = new QLineEdit(gb_modelInfo);
	ledit_modelName->setGeometry(QRect(76, 22, 161, 20));

	lb_modelId = new QLabel(gb_modelInfo);
	lb_modelId->setGeometry(QRect(299, 22, 48, 16));
	ledit_modelId = new QLineEdit(gb_modelInfo);
	ledit_modelId->setGeometry(QRect(365, 22, 161, 20));
	ledit_modelId->setEnabled(false);

	lb_version = new QLabel(gb_modelInfo);
	lb_version->setGeometry(QRect(10, 48, 48, 16));
	ledit_version = new QLineEdit(gb_modelInfo);
	ledit_version->setGeometry(QRect(76, 48, 161, 20));
	ledit_version->setEnabled(false);

	lb_subject = new QLabel(gb_modelInfo);
	lb_subject->setGeometry(QRect(299, 48, 60, 16));
	ledit_subject = new QLineEdit(gb_modelInfo);
	ledit_subject->setGeometry(QRect(365, 48, 161, 20));

	lb_type = new QLabel(gb_modelInfo);
	lb_type->setGeometry(QRect(10, 74, 60, 16));
	combox_type = new QComboBox(gb_modelInfo);
	combox_type->setGeometry(QRect(76, 74, 161, 20));
	readTypeInfo();
	combox_type->addItems(m_typeList);

	lb_property = new QLabel(gb_modelInfo);
	lb_property->setGeometry(QRect(299, 74, 60, 16));
	combox_property = new QComboBox(gb_modelInfo);
	combox_property->setGeometry(QRect(365, 74, 161, 20));
	combox_property->addItems(m_propertyList);

	lb_group = new QLabel(gb_modelInfo);
	lb_group->setGeometry(QRect(10, 100, 60, 16));
	combox_group = new QComboBox(gb_modelInfo);
	combox_group->setGeometry(QRect(76, 100, 161, 20));
	readGroupInfo();
	combox_group->addItems(m_groupList);

	lb_descript = new QLabel(gb_modelInfo);
	lb_descript->setGeometry(QRect(10, 126, 60, 16));
	ledit_descript = new QLineEdit(gb_modelInfo);
	ledit_descript->setGeometry(QRect(76, 126, 450, 20));

	lb_log = new QLabel(gb_modelInfo);
	lb_log->setGeometry(QRect(10, 152, 60, 16));
	tedit_log = new QTextEdit(gb_modelInfo);
	tedit_log->setGeometry(QRect(76, 152, 450, 40));

	lb_author = new QLabel(gb_modelInfo);
	lb_author->setGeometry(QRect(299, 100, 60, 16));
	ledit_author = new QLineEdit(gb_modelInfo);
	ledit_author->setGeometry(QRect(365, 100, 161, 20));

	lb_update = new QLabel(gb_modelInfo);
	lb_update->setGeometry(QRect(10, 198, 60, 16));
	date_update = new QDateTimeEdit(QDate::currentDate(), gb_modelInfo);
	date_update->setDisplayFormat("yyyy-M-d");
	date_update->setGeometry(QRect(76, 198, 161, 20));
	date_update->setCalendarPopup(true);
	
	
	gb_fileInfo = new QGroupBox(this);
	gb_fileInfo->setGeometry(QRect(9, 310, 552, 266));
	gridLayout = new QGridLayout(gb_fileInfo);
	tv_fileInfo = new QTableView(gb_fileInfo);

	gridLayout->addWidget(tv_fileInfo, 0, 0, 1, 3);
	btn_add = new QPushButton(gb_fileInfo);

	gridLayout->addWidget(btn_add, 1, 1, 1, 1);
	btn_delete = new QPushButton(gb_fileInfo);
	btn_delete->setEnabled(false);
	
	gridLayout->addWidget(btn_delete, 1, 2, 1, 1);
	hSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
	gridLayout->addItem(hSpacer, 1, 0, 1, 1);

	gb_modelInfo->setTitle("ģ����Ϣ");
	gb_fileInfo->setTitle("ģ���ļ���Ϣ");
	lb_modelName->setText("ģ������");
	lb_modelId->setText("ģ��id");
	lb_version->setText("�汾��");
	lb_subject->setText("ѧ����Ϣ");
	lb_type->setText("�ͺ�");
	lb_property->setText("ģ������");
	lb_group->setText("ģ�ͷ���");
	lb_descript->setText("ģ������");
	lb_log->setText("��־��Ϣ");
	lb_author->setText("������");
	lb_update->setText("��������");
	btn_add->setText("����ļ�");
	btn_delete->setText("ɾ���ļ�");

	QStandardItemModel *fileInfo = new QStandardItemModel();
	tbViewInit(fileInfo);
	tv_fileInfo->setModel(fileInfo);

	tv_fileInfo->horizontalHeader()->setStretchLastSection(true);
	tv_fileInfo->verticalHeader()->setHidden(true);
	tv_fileInfo->setSelectionBehavior(QAbstractItemView::SelectRows);

	//���QTableView�е��Ҽ�����
	tv_fileInfo->setContextMenuPolicy(Qt::CustomContextMenu);
	connect(tv_fileInfo, SIGNAL(customContextMenuRequested(const QPoint&)), 
		this, SLOT(showContextMenu(const QPoint&)));

	menu_right = new QMenu(tv_fileInfo);
	QAction *actionDelete = menu_right->addAction("ɾ��");
	connect(actionDelete, SIGNAL(triggered()), this, SLOT(OnDelete()));

	connect(btn_add, SIGNAL(clicked()), this, SLOT(OnAppend()));
	connect(btn_delete, SIGNAL(clicked()) ,this, SLOT(OnDelete()));

}

CreatModel::~CreatModel(void)
{
}

/************************************************************
* ����		: ��ʼ��tableView
* ����		: QStandardItemModel
* ����ֵ	: void
*************************************************************/
void CreatModel::tbViewInit(QStandardItemModel *itemmodel)
{
	itemmodel->setColumnCount(3);
	QStringList sHeaderList;
	sHeaderList << "��  ��" << "�� ��" << "· ��";
	itemmodel->setHorizontalHeaderLabels(sHeaderList);
}

/************************************************************
* ����		: ��QTableView������ļ�
* ����		: ��
* ����ֵ	: void
*************************************************************/
void CreatModel::OnAppend()
{
	m_sAllList = QStringList();
	QString sInfoFile;
	QFileDialog* dialogFiles = new QFileDialog(this,"ѡ���ļ�");
	dialogFiles->setFileMode(QFileDialog::ExistingFiles);
	dialogFiles->setFilter("All Files (*.*)");
	dialogFiles->setViewMode(QFileDialog::List);

	if (dialogFiles->exec() == QDialog::Accepted) 
	{       
		m_sCurrentList = dialogFiles->selectedFiles();
		m_sAllList += m_sCurrentList;
		m_sAllList.removeDuplicates();
		showFileInfo(m_sAllList);
	}
}

/************************************************************
* ����		: ��QTableView����ʾѡ���ļ�����Ϣ
* ����		: QStringList
* ����ֵ	: void
*************************************************************/
void CreatModel::showFileInfo(QStringList slist)
{
	tbViewInit(m_infos);

	for (int i = 0; i < slist.size(); i++)
	{
		QString filePath = slist.at(i);
		QFileInfo fileInfo(filePath);
		QString fileName = fileInfo.fileName(); 
		QString fileDescript = "";

		QStandardItem *itemName = new QStandardItem(fileName);
		QStandardItem *itemDescript = new QStandardItem(fileDescript);
		QStandardItem *itemPath = new QStandardItem(filePath);
		m_infos->setItem(i, 0, itemName);
		m_infos->setItem(i, 1, itemDescript);
		m_infos->setItem(i, 2, itemPath);

		tv_fileInfo->setModel(m_infos);
		m_flag = i + 1;
		
		btn_delete->setEnabled(true);
	}
}

/************************************************************
* ����		: //ɾ��QTableView�б�ѡ�е���
* ����		: ��
* ����ֵ	: void
*************************************************************/
void CreatModel::OnDelete()
{
	QItemSelectionModel *ismItem =  tv_fileInfo->selectionModel();
	QModelIndex index = ismItem->currentIndex();
	m_infos->removeRow(index.row());

	m_flag--;

	if (m_flag == 0)
	{
		btn_delete->setEnabled(false);
	}
}

/************************************************************
* ����		: �������ϵ���Ϣ���浽 xx.xml�ļ���
* ����		: ��
* ����ֵ	: void
*************************************************************/
bool CreatModel::OnSave()
{
	if (m_flagName.isEmpty())
	{
		return OnSaveAs();
	}
    return saveFile(m_flagName);
}

/************************************************************
* ����		: �ļ����Ϊ��Ӧ
* ����		: ��
* ����ֵ	: void
*************************************************************/
bool CreatModel::OnSaveAs()
{
	QString filename = QFileDialog::getSaveFileName( this, "Save", "model", "*.xml" );  
	if (filename.isEmpty())
		return false;
	return saveFile(filename);
}

/************************************************************
* ����		: �������ݵ�ָ���ļ�
* ����		: �ļ���
* ����ֵ	: void
*************************************************************/
bool CreatModel::saveFile(QString fileName)
{
	QFile file( fileName );  
	if( !file.open(QIODevice::WriteOnly | QIODevice::Text) )  
	{  
		return false;   
	}  

	QString sName = ledit_modelName->text();
	QString sId = ledit_modelId->text();
	QString sVersion = ledit_version->text();
	QString sSubject = ledit_subject->text();
	QString sType = combox_type->currentText();
	QString sProperty = combox_property->currentText();
	QString sGroup = combox_group->currentText();
	QString sDescription = ledit_descript->text();
	QString sLog = tedit_log->toPlainText();
	QString sAuthor = ledit_author->text();
	QString sUpdate = date_update->text();

	QDomDocument document; 
	QString strHeader( "version=\"1.0\" encoding=\"UTF-8\"" );  
	document.appendChild( document.createProcessingInstruction("xml", strHeader) );  

	QDomElement root_elem = document.createElement( "project" );  
	root_elem.setAttribute( "name", sName );  
	root_elem.setAttribute( "id", sId );  
	root_elem.setAttribute( "version", sVersion );  
	root_elem.setAttribute( "subject", sSubject ); 
	root_elem.setAttribute( "type", sType );  
	root_elem.setAttribute( "property", sProperty );  
	root_elem.setAttribute( "group", sGroup );  
	root_elem.setAttribute( "description", sDescription ); 
	root_elem.setAttribute( "log", sLog );  
	root_elem.setAttribute( "author", sAuthor );  
	root_elem.setAttribute( "update_date", sUpdate ); 
	document.appendChild(root_elem);

	//��ȡtableView�е���Ϣ  ����Ϣ����
	if (m_flag == 0)
	{
		QDomElement itemFile = document.createElement( "file" );  
		itemFile.setAttribute( "name", "" ); 
		itemFile.setAttribute( "description", "" );  
		itemFile.setAttribute( "path", "" );  
		root_elem.appendChild( itemFile );
	}
	else
	{
		for (int i = 0; i < m_flag; i++)
		{
			QString sfileName = m_infos->item(i, 0)->text();
			QString sfileDescript = m_infos->item(i, 1)->text();
			QString sfilePath = m_infos->item(i, 2)->text();

			QDomElement itemFile = document.createElement( "file" );  
			itemFile.setAttribute( "name", sfileName ); 
			itemFile.setAttribute( "description", sfileDescript );  
			itemFile.setAttribute( "path", sfilePath );  
			root_elem.appendChild( itemFile );
		}
	}
	QTextStream out( &file );  
	document.save( out, 4 );  
	file.close();  
	QMessageBox::information(this, "ģ�͹����װ����", "�ļ�����ɹ���");
	return true;
}

/************************************************************
* ����		: "��ʼ"-->"�½�" ��Ӧ
* ����		: ��
* ����ֵ	: void
*************************************************************/
void CreatModel::OnNew()
{

	clearInfo();
	m_flagName = "";
	lb_filePath->setText("");
}

/************************************************************
* ����		: �½�--��ս�����Ϣ
* ����		: ��
* ����ֵ	: void
*************************************************************/
void CreatModel::clearInfo()
{
	ledit_modelName->setText("");
	ledit_modelId->setText("");
	ledit_version->setText("");
	ledit_subject->setText("");
	combox_type->setCurrentIndex(0);
	combox_property->setCurrentIndex(0);
	combox_group->setCurrentIndex(0);
	ledit_descript->setText("");
	tedit_log->setText("");
	ledit_author->setText("");
	date_update->setDate(QDate::currentDate());

	if (m_infos)
	{
		m_infos->clear();
		m_flag = 0;
		btn_delete->setEnabled(false);
		tbViewInit(m_infos);
	}
}

/************************************************************
* ����		: �˳�����
* ����		: ��
* ����ֵ	: void
*************************************************************/
void CreatModel::OnQuit()
{
	if (QMessageBox::information(this,"�˳�","ȷ���˳�ģ�ͷ�װ����?",
		QMessageBox::Ok | QMessageBox::Cancel) == QMessageBox::Ok)
	{
		this->close();
	}
}


/************************************************************
* ����		:"��ʼ" --> "��" ������Ӧ
* ����		: ��
* ����ֵ	: void
*************************************************************/
void CreatModel::OnOpen()
{
	//TODO:�ж�ԭ���ļ��Ƿ񱣴�

	QString fileName = QFileDialog::getOpenFileName(NULL, tr("Open File"),"", "*.xml");
	if (fileName.isEmpty())
	{
		return;
	}
	openXml(fileName);
	showAllInfo();

	lb_filePath->setText(fileName);
	lb_filePath->setWordWrap(true);

	m_flagName = fileName;	
}

/************************************************************
* ����		: ��xx.xml�ļ�
* ����		: �ļ�·��
* ����ֵ	: void
*************************************************************/
void CreatModel::openXml(QString sFileName)
{
	QFile xml(sFileName);
	if( !xml.open(QIODevice::ReadOnly | QIODevice::Text) )  
	{  
		return;  
	}  

	QString errorStr;
	int errorLine;
	int errorColumn;

	m_domDocument = new QDomDocument();
	if (!m_domDocument->setContent(&xml, false, &errorStr, &errorLine, &errorColumn))
	{
		return ;
	}
	m_root = m_domDocument->documentElement();
}

/************************************************************
* ����		: ��ȡxx.xml�е���Ϣ ��ʾ�ڽ���
* ����		: ��
* ����ֵ	: void
*************************************************************/
void CreatModel::showAllInfo()
{
	m_fileInfo = QStringList();
	if (m_root.isElement()) 
	{
		QString sName = m_root.attributeNode("name").value();
		QString sId = m_root.attributeNode("id").value();
		QString sVersion = m_root.attributeNode("version").value();
		QString sSubject = m_root.attributeNode("subject").value();
		QString sType = m_root.attributeNode("type").value();
		QString sProperty = m_root.attributeNode("property").value();
		QString sGroup = m_root.attributeNode("group").value();
		QString sDescription = m_root.attributeNode("description").value();
		QString sAuthor = m_root.attributeNode("author").value();
		QString sLog = m_root.attributeNode("log").value();
		QString sUpdate = m_root.attributeNode("update_date").value();

		ledit_modelName->setText(sName);
		ledit_modelId->setText(sId);
		lb_modelId->setEnabled(true);
		ledit_modelId->setEnabled(true);
		ledit_modelId->setReadOnly(true);

		ledit_version->setText(sVersion);
		lb_version->setEnabled(true);
		ledit_version->setEnabled(true);
		ledit_version->setReadOnly(true);
		ledit_subject->setText(sSubject);

		int typeIndex = combox_type->findText(sType);
		combox_type->setCurrentIndex(typeIndex);
		int proIndex = combox_property->findText(sProperty);
		combox_property->setCurrentIndex(proIndex);
		int groupIndex = combox_group->findText(sGroup);
		combox_group->setCurrentIndex(groupIndex);

		ledit_descript->setText(sDescription);
		ledit_author->setText(sAuthor);
		tedit_log->setText(sLog);
		date_update->setDate(QDate::fromString(sUpdate, "yyyy-M-d"));
	}

	QDomNode n = m_root.firstChild();
	QString sAllInfo = "";
	while (!n.isNull())
	{
		if (n.isElement())
		{
			QString fileName = n.toElement().attributeNode("name").value();
			QString filePath = n.toElement().attributeNode("path").value();
			QString fileDescript = n.toElement().attributeNode("description").value();
			sAllInfo = fileName + ";" + fileDescript + ";" + filePath;
		}
		n = n.nextSibling();
		m_fileInfo.append(sAllInfo);
	}
	readFileInfo(m_fileInfo);
}

/************************************************************
* ����		: ��sAllInfo�е���Ϣ����������
* ����		: QStringList
* ����ֵ	: void
*************************************************************/
void CreatModel::readFileInfo(QStringList sListInfo)
{
	tbViewInit(m_infos);

	for (int i = 0; i < sListInfo.size(); i++)
	{
		QString fileInfo = sListInfo.at(i);
		QStringList sList = fileInfo.split(";");

		QString fileName = sList.at(0);
		QString fileDescript = sList.at(1);
		QString filePath = sList.at(2);

		QStandardItem *itemName = new QStandardItem(fileName);
		QStandardItem *itemDescript = new QStandardItem(fileDescript);
		QStandardItem *itemPath = new QStandardItem(filePath);
		m_infos->setItem(i, 0, itemName);
		m_infos->setItem(i, 1, itemDescript);
		m_infos->setItem(i, 2, itemPath);

		m_flag = i + 1;
	}
	tv_fileInfo->setModel(m_infos);
	
	btn_delete->setEnabled(true);
}


/************************************************************
* ����		: ��itemmodel������Ҽ�����
* ����		: ��
* ����ֵ	: void
*************************************************************/
void CreatModel::showContextMenu(const QPoint& pos)
{

	QItemSelectionModel *ismItem =  tv_fileInfo->selectionModel();
	QModelIndex index = ismItem->currentIndex();
	int sRow = 0;
	sRow = index.row();

	if(menu_right && sRow != -1)
	{
		menu_right->exec(QCursor::pos());
	}
}

/************************************************************
* ����		: ��type_property.xml�ж�ȡtype��property��������Ϣ
* ����		: 
* ����ֵ	: void
*************************************************************/
void CreatModel::readTypeInfo()
{
	openXml(QDir::currentPath() + "/Config/type_property.xml");
	
	QDomNode n = m_root.firstChild();
	while(!n.isNull())
	{
		QString nodeName = n.nodeName();
		if (nodeName == "typelist")
		{
			QDomNode m = n.toElement().firstChild();
			while (m.isElement())
			{
				QString nameValue = m.toElement().attributeNode("name").value();
				m_typeList.append(nameValue);
				m = m.nextSibling();
			}
		}
		if (nodeName == "propertylist")
		{
			QDomNode m = n.toElement().firstChild();
			while (m.isElement())
			{
				QString nameValue = m.toElement().attributeNode("name").value();
				m_propertyList.append(nameValue);
				m = m.nextSibling();
			}
		}
		n = n.nextSibling();
	}
}

/************************************************************
* ����		: ��group.xml�ж�ȡgroup��������Ϣ
* ����		: 
* ����ֵ	: void
*************************************************************/
void CreatModel::readGroupInfo()
{
	openXml(QDir::currentPath() + "/Config/group.xml");

	QDomNode n = m_root.firstChild();
	while(!n.isNull())
	{
		QString nodeName = n.nodeName();
		if (nodeName == "grouplist")
		{
			QDomNode m = n.toElement().firstChild();
			while (m.isElement())
			{
				QString nameValue = m.toElement().attributeNode("name").value();
				m_groupList.append(nameValue);
				m = m.nextSibling();
			}
		}
		n = n.nextSibling();
	}
}

/************************************************************
* ����		: ����ģ�͹��������Ϊ�������
* ����		: QWidget** �� QWidget* 
* ����ֵ	: void
*************************************************************/
void creatModel(QWidget** pWidget,QWidget* pParent)
{
	CreatModel *pModel = new CreatModel(pParent);
	*pWidget = (QWidget*)pModel;
}	