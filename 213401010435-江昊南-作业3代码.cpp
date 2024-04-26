#include<stdio.h>
#include<stdlib.h>	
#include<string.h>	
#include<stdbool.h>	
#include<iostream>
using namespace std;

typedef struct Nnode {
	int Ndat;//结点值
	struct Nnode* Nnext;//下一个结点
}Nnode, * nnode;

typedef struct Normal {
	struct Nnode* nFront;//队首指针
	struct Nnode* nRear;//队尾指针
}Normal, * nNormal;
//创建链式队列
Normal* nCreatLinkQueue(void)
{
	nNormal nHeadQueue = NULL;//链式队列指针
	nnode nHeadNode = NULL;//头结点指针
	//为链式队列申请内存
	nHeadQueue = (Normal*)malloc(sizeof(Normal));
	if (nHeadQueue == NULL) {
		printf("队列内存申请失败，程序终止......\r\n");
		while (1);
	}
	//为链式队列头结点申请内存
	nHeadNode = (Nnode *)malloc(sizeof(Nnode));
	if (nHeadNode == NULL)
	{
		printf("队列头结点内存申请失败，程序终止......\r\n");
		while (1);
	}

	nHeadQueue->nFront = nHeadNode;//队首指向头结点
	nHeadQueue->nRear = nHeadNode;//队尾指向头结点
	nHeadNode->Nnext = NULL;//头结点无下个结点
	nHeadNode->Ndat = 0;//头结点数据为零
	printf("链式队列创建成功......\r\n");
	return nHeadQueue;
}

void nEnterLinkQueue(nNormal queue, int value)
{
	nnode NnewNode = NULL;//链式队列入队结点指针
	//为链式队列入队结点申请内存
	NnewNode = (Nnode*)malloc(sizeof(Nnode));
	if (NnewNode == NULL)
	{
		printf("入队申请失败......\r\n");
		return;
	}
	queue->nRear->Nnext = NnewNode;//入队新结点为最后个结点
	queue->nRear = NnewNode;//队尾指向入队新结点
	NnewNode->Nnext = NULL;//入队新结点无下个结点
	NnewNode->Ndat = value;//入队值
	cout << "                                                          加入成功";
	cout << "                                                          若要继续程序则输入操作数“1”：";
}

bool nIsEmptyLinkQueue(nNormal queue)
{
	//队首与队尾指向同一节(首节点)点则队列为空
	if (queue->nFront == queue->nRear)
		return true;
	else
		return false;
}

void nTraverseLinkQueue(nNormal queue)
{
	nnode queNode = NULL;//结点指针

	if (nIsEmptyLinkQueue(queue))
	{
		printf("队伍为空\r\n");
		return;
	}

	cout<<"                                                          当前普通候诊人员（由左向右）: ";
	queNode = queue->nFront->Nnext;//第一个有效结点
	while (queNode != NULL)//最后一个结点结束
	{
		printf("%d ", queNode->Ndat);//结点数据
		queNode = queNode->Nnext;//下一个结点
	}
	printf("\r\n");
}
//链式队列数据出队
void nOutLinkQueue(nNormal queue, int* value)
{
	nnode queNode = 0;//队列结点指针
	if (nIsEmptyLinkQueue(queue))
	{
		printf("缺失数据\r\n");
		*value = 0;
		return;
	}
	if (queue->nFront->Nnext == queue->nRear)//只有一个有效结点
		queue->nRear = queue->nFront;//队尾指针等于队首指针
	queNode = queue->nFront->Nnext;//结点指针指向队首有效结点
	queue->nFront->Nnext = queNode->Nnext;//队首结点指针指向下个结点
	*value = queNode->Ndat;//出队结点值
	free(queNode);//释放内存
	cout << "                                                          当前普通就诊者号码：" << *value;
	cout << "                                                          若要继续程序则输入操作数“1”：";
}

int nCountLinkQueue(nNormal queue)
{
	nnode queNode = NULL;//结点指针
	int len = 0;
	if (nIsEmptyLinkQueue(queue))
	{
		printf("队列为空......\r\n");
		return len;
	}

	queNode = queue->nFront->Nnext;//第一个有效结点
	while (queNode != NULL)//最后一个结点结束
	{
		len++;
		queNode = queNode->Nnext;//下一个结点
	}

	printf("                                                          普通候诊人数: %d\r\n", len);
	return len;
}


typedef struct Enode {
	int Edat;//结点值
	struct Enode* Enext;//下一个结点
}Enode, * enode;

typedef struct Emergency {
	struct Enode* eFront;//队首指针
	struct Enode* eRear;//队尾指针
}Emergency, * eEmergency;
//创建链式队列
Emergency* eCreatLinkQueue(void)
{
	 eEmergency eHeadQueue = NULL;//链式队列指针
	enode eHeadNode = NULL;//头结点指针
	//为链式队列申请内存
	eHeadQueue = (Emergency*)malloc(sizeof(Emergency));
	if (eHeadQueue == NULL)
	{
		printf("链式队列内存申请失败，程序终止......\r\n");
		while (1);
	}
	//为链式队列头结点申请内存
	eHeadNode = (Enode*)malloc(sizeof(Enode));
	if (eHeadNode == NULL)
	{
		printf("链式队列头结点内存申请失败，程序终止......\r\n");
		while (1);
	}
	eHeadQueue->eFront = eHeadNode;//队首指向头结点
	eHeadQueue->eRear = eHeadNode;//队尾指向头结点
	eHeadNode->Enext = NULL;//头结点无下个结点
	eHeadNode->Edat = 0;//头结点数据为零
	printf("链式队列创建成功......\r\n");
	return eHeadQueue;
}

void eEnterLinkQueue(eEmergency queue, int value)
{
	enode enewNode = NULL;//链式队列入队结点指针
	//为链式队列入队结点申请内存
	enewNode = (Enode*)malloc(sizeof(Enode));
	if (enewNode == NULL)
	{
		printf("入队申请失败......\r\n");
		return;
	}
	queue->eRear->Enext = enewNode;//入队新结点为最后个结点
	queue->eRear = enewNode;//队尾指向入队新结点
	enewNode->Enext = NULL;//入队新结点无下个结点
	enewNode->Edat = value;//入队值
	cout << "                                                          加入成功";
	cout << "                                                          若要继续程序则输入操作数“1”：";
}

bool eIsEmptyLinkQueue(eEmergency queue)
{
	//队首与队尾指向同一节(首节点)点则队列为空
	if (queue->eFront == queue->eRear)
		return true;
	else
		return false;
}

void eTraverseLinkQueue(eEmergency queue)
{
	enode queNode = NULL;//结点指针

	if (eIsEmptyLinkQueue(queue))
	{
		printf("队列为空\r\n");
		return;
	}

	cout << "                                                          当前紧急候诊人员（由左向右）: ";
	queNode = queue->eFront->Enext;//第一个有效结点
	while (queNode != NULL)//最后一个结点结束
	{
		printf("%d ", queNode->Edat);//结点数据
		queNode = queNode->Enext;//下一个结点
	}
	printf("\r\n");
}

void eOutLinkQueue(eEmergency queue, int* value)
{
	enode queNode = 0;//队列结点指针

	if (eIsEmptyLinkQueue(queue))
	{
		printf("缺失数据\r\n");
		*value = 0;
		return;
	}

	if (queue->eFront->Enext == queue->eRear)//只有一个有效结点
		queue->eRear = queue->eFront;//队尾指针等于队首指针

	queNode = queue->eFront->Enext;//结点指针指向队首有效结点
	queue->eFront->Enext = queNode->Enext;//队首结点指针指向下个结点
	*value = queNode->Edat;//出队结点值
	free(queNode);//释放内存

	cout << "                                                          当前紧急就诊者号码：" << *value;
	cout << "                                                          若要继续程序则输入操作数“1”：";
}

int eCountLinkQueue(eEmergency queue)
{
	enode queNode = NULL;//结点指针
	int len = 0;

	if (eIsEmptyLinkQueue(queue))
	{
		printf("链式队列为空......\r\n");
		return len;
	}

	queNode = queue->eFront->Enext;//第一个有效结点
	while (queNode != NULL)//最后一个结点结束
	{
		len++;
		queNode = queNode->Enext;//下一个结点
	}

	printf("                                                          紧急候诊人数: %d\r\n", len);
	return len;
}

int main() {
	nNormal N;
	eEmergency E;
	N = nCreatLinkQueue();//创建链式队列
	E = eCreatLinkQueue();
	int ndelVal = 0;
	int edelVal = 0;
	while (true) {
		system("cls");
		cout << "                                                               1，加入普通病人信息（普通就诊）                \n";
		cout << "                                                               2，加入紧急病人信息（紧急就诊）                \n";
		cout << "                                                               3，查看当前普通就诊排队人数与当前就诊者\n";
		cout << "                                                               4，查看当前紧急就诊排队人数与当前就诊者\n";
		cout << "                                                               5，退出程序                                                        \n";
		cout << "                                                              请输入操作数：";
		int kind;
		cin >> kind;
		cout << "-----------------------------------------------------------------------------------------------------------------\n";
		switch (kind) {
		case 1: {
			cout << "                                                          请输入普通就诊病人号码：";
			int Nnumber;
			cin >> Nnumber;
			nEnterLinkQueue(N, Nnumber); 
			int nkind;
			cin >> nkind;
			switch (nkind) {
			case 1:continue;
			}
		}break;
			case 2: {
				cout << "                                                      请输入紧急就诊病人号码：";
				int Enumber;
				cin >> Enumber;
				eEnterLinkQueue(E, Enumber);
				int ekind;
				cin >> ekind;
				switch (ekind) {
				case 1:continue;
				}
			}break;
			case 3: {
				nCountLinkQueue(N);
				nTraverseLinkQueue(N);
				nOutLinkQueue(N, &ndelVal);
				int Nkind;
				cin >> Nkind;
				switch (Nkind) {
				case 1:continue;
				}
			}break;
			case 4: {
				eCountLinkQueue(E);
				eTraverseLinkQueue(E);
				eOutLinkQueue(E, &edelVal);
				int Ekind;
				cin >> Ekind;
				switch (Ekind) {
				case 1:continue;
				}
			}break;
			case 5: {
				exit(0);
			}break;
		}
	}
	return 0;
}