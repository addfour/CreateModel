/****************************************************************************
* �ļ���		: CreatModel.h
* ����			: ģ�ͷ�װ����
* ������		: LiuC - CSSRC
* �޸���־		: Created on 2012.03.21
*****************************************************************************/
#pragma once
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QMenuBar>
#include <QtCore/QStringList>
#include <QtXml/QDomDocument>
#include <QtGui/QStandardItemModel>
#include <QtGui/QComboBox>
#include <QtGui/QDateTimeEdit>
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>


// ����ģ�͹����ߣ������ɿ�ܵ���
void creatModel(QWidget** pWidget,QWidget* pParent);

class CreatModel :
	public QDialog
{
	Q_OBJECT
public:
	CreatModel(QWidget* parent = 0);
	~CreatModel(void);
	
private:
	//QMenuBar  *menuBar;
	QPushButton *btn_new;
	QPushButton *btn_open;
	QPushButton *btn_save;
	QPushButton *btn_saveAs;
	QLabel      *lb_filePath;

	QGroupBox *gb_modelInfo;
	QLabel    *lb_modelName;
	QLabel    *lb_modelId;
	QLabel    *lb_version;
	QLabel    *lb_subject;
	QLabel    *lb_type;
	QLabel    *lb_property;
	QLabel    *lb_group;
	QLabel    *lb_author;
	QLabel    *lb_descript;
	QLabel    *lb_log;
	QLabel    *lb_update;
	QLineEdit *ledit_modelName;
	QLineEdit *ledit_modelId;
	QLineEdit *ledit_version;
	QLineEdit *ledit_subject;
	QComboBox *combox_type;
	QComboBox *combox_property;
	QComboBox *combox_group;
	QLineEdit *ledit_author;
	QLineEdit *ledit_descript;
	QTextEdit *tedit_log;
	QDateTimeEdit *date_update;
	
	QGroupBox   *gb_fileInfo;
	QGridLayout *gridLayout;
	QTableView  *tv_fileInfo;
	QPushButton *btn_add;
	QPushButton *btn_delete;
	QSpacerItem *hSpacer;
	QMenu       *menu_right;

	QStringList  m_sCurrentList;
	QStringList  m_sAllList;
	QStringList  m_fileInfo;
	QDomDocument *m_pXmlDocument;
	QStandardItemModel *m_infos;
	int m_flag; //������ǵ�ǰQTableView������
	QDomDocument *m_domDocument;
	QDomElement   m_root;
	QStringList   m_typeList;
	QStringList   m_propertyList;
	QStringList   m_groupList;
	QString m_flagName;//������ǵ�ǰ���ļ�������

private slots:
	void OnAppend();
	void OnDelete();
	void OnNew();
	bool OnSave();
	bool OnSaveAs();
	void OnOpen();
	void OnQuit();
	void showContextMenu(const QPoint& pos);

private:
	void showFileInfo(QStringList slist);
	void tbViewInit(QStandardItemModel *itemmodel);
	void openXml(QString sFileName);
	void readTypeInfo();
	void readGroupInfo();
	void readFileInfo(QStringList sFileInfo);
	void showAllInfo();
	bool saveFile(QString fileName);
	void clearInfo();
	
};
