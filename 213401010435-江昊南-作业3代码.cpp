#include<stdio.h>
#include<stdlib.h>	
#include<string.h>	
#include<stdbool.h>	
#include<iostream>
using namespace std;

typedef struct Nnode {
	int Ndat;//���ֵ
	struct Nnode* Nnext;//��һ�����
}Nnode, * nnode;

typedef struct Normal {
	struct Nnode* nFront;//����ָ��
	struct Nnode* nRear;//��βָ��
}Normal, * nNormal;
//������ʽ����
Normal* nCreatLinkQueue(void)
{
	nNormal nHeadQueue = NULL;//��ʽ����ָ��
	nnode nHeadNode = NULL;//ͷ���ָ��
	//Ϊ��ʽ���������ڴ�
	nHeadQueue = (Normal*)malloc(sizeof(Normal));
	if (nHeadQueue == NULL) {
		printf("�����ڴ�����ʧ�ܣ�������ֹ......\r\n");
		while (1);
	}
	//Ϊ��ʽ����ͷ��������ڴ�
	nHeadNode = (Nnode *)malloc(sizeof(Nnode));
	if (nHeadNode == NULL)
	{
		printf("����ͷ����ڴ�����ʧ�ܣ�������ֹ......\r\n");
		while (1);
	}

	nHeadQueue->nFront = nHeadNode;//����ָ��ͷ���
	nHeadQueue->nRear = nHeadNode;//��βָ��ͷ���
	nHeadNode->Nnext = NULL;//ͷ������¸����
	nHeadNode->Ndat = 0;//ͷ�������Ϊ��
	printf("��ʽ���д����ɹ�......\r\n");
	return nHeadQueue;
}

void nEnterLinkQueue(nNormal queue, int value)
{
	nnode NnewNode = NULL;//��ʽ������ӽ��ָ��
	//Ϊ��ʽ������ӽ�������ڴ�
	NnewNode = (Nnode*)malloc(sizeof(Nnode));
	if (NnewNode == NULL)
	{
		printf("�������ʧ��......\r\n");
		return;
	}
	queue->nRear->Nnext = NnewNode;//����½��Ϊ�������
	queue->nRear = NnewNode;//��βָ������½��
	NnewNode->Nnext = NULL;//����½�����¸����
	NnewNode->Ndat = value;//���ֵ
	cout << "                                                          ����ɹ�";
	cout << "                                                          ��Ҫ���������������������1����";
}

bool nIsEmptyLinkQueue(nNormal queue)
{
	//�������βָ��ͬһ��(�׽ڵ�)�������Ϊ��
	if (queue->nFront == queue->nRear)
		return true;
	else
		return false;
}

void nTraverseLinkQueue(nNormal queue)
{
	nnode queNode = NULL;//���ָ��

	if (nIsEmptyLinkQueue(queue))
	{
		printf("����Ϊ��\r\n");
		return;
	}

	cout<<"                                                          ��ǰ��ͨ������Ա���������ң�: ";
	queNode = queue->nFront->Nnext;//��һ����Ч���
	while (queNode != NULL)//���һ��������
	{
		printf("%d ", queNode->Ndat);//�������
		queNode = queNode->Nnext;//��һ�����
	}
	printf("\r\n");
}
//��ʽ�������ݳ���
void nOutLinkQueue(nNormal queue, int* value)
{
	nnode queNode = 0;//���н��ָ��
	if (nIsEmptyLinkQueue(queue))
	{
		printf("ȱʧ����\r\n");
		*value = 0;
		return;
	}
	if (queue->nFront->Nnext == queue->nRear)//ֻ��һ����Ч���
		queue->nRear = queue->nFront;//��βָ����ڶ���ָ��
	queNode = queue->nFront->Nnext;//���ָ��ָ�������Ч���
	queue->nFront->Nnext = queNode->Nnext;//���׽��ָ��ָ���¸����
	*value = queNode->Ndat;//���ӽ��ֵ
	free(queNode);//�ͷ��ڴ�
	cout << "                                                          ��ǰ��ͨ�����ߺ��룺" << *value;
	cout << "                                                          ��Ҫ���������������������1����";
}

int nCountLinkQueue(nNormal queue)
{
	nnode queNode = NULL;//���ָ��
	int len = 0;
	if (nIsEmptyLinkQueue(queue))
	{
		printf("����Ϊ��......\r\n");
		return len;
	}

	queNode = queue->nFront->Nnext;//��һ����Ч���
	while (queNode != NULL)//���һ��������
	{
		len++;
		queNode = queNode->Nnext;//��һ�����
	}

	printf("                                                          ��ͨ��������: %d\r\n", len);
	return len;
}


typedef struct Enode {
	int Edat;//���ֵ
	struct Enode* Enext;//��һ�����
}Enode, * enode;

typedef struct Emergency {
	struct Enode* eFront;//����ָ��
	struct Enode* eRear;//��βָ��
}Emergency, * eEmergency;
//������ʽ����
Emergency* eCreatLinkQueue(void)
{
	 eEmergency eHeadQueue = NULL;//��ʽ����ָ��
	enode eHeadNode = NULL;//ͷ���ָ��
	//Ϊ��ʽ���������ڴ�
	eHeadQueue = (Emergency*)malloc(sizeof(Emergency));
	if (eHeadQueue == NULL)
	{
		printf("��ʽ�����ڴ�����ʧ�ܣ�������ֹ......\r\n");
		while (1);
	}
	//Ϊ��ʽ����ͷ��������ڴ�
	eHeadNode = (Enode*)malloc(sizeof(Enode));
	if (eHeadNode == NULL)
	{
		printf("��ʽ����ͷ����ڴ�����ʧ�ܣ�������ֹ......\r\n");
		while (1);
	}
	eHeadQueue->eFront = eHeadNode;//����ָ��ͷ���
	eHeadQueue->eRear = eHeadNode;//��βָ��ͷ���
	eHeadNode->Enext = NULL;//ͷ������¸����
	eHeadNode->Edat = 0;//ͷ�������Ϊ��
	printf("��ʽ���д����ɹ�......\r\n");
	return eHeadQueue;
}

void eEnterLinkQueue(eEmergency queue, int value)
{
	enode enewNode = NULL;//��ʽ������ӽ��ָ��
	//Ϊ��ʽ������ӽ�������ڴ�
	enewNode = (Enode*)malloc(sizeof(Enode));
	if (enewNode == NULL)
	{
		printf("�������ʧ��......\r\n");
		return;
	}
	queue->eRear->Enext = enewNode;//����½��Ϊ�������
	queue->eRear = enewNode;//��βָ������½��
	enewNode->Enext = NULL;//����½�����¸����
	enewNode->Edat = value;//���ֵ
	cout << "                                                          ����ɹ�";
	cout << "                                                          ��Ҫ���������������������1����";
}

bool eIsEmptyLinkQueue(eEmergency queue)
{
	//�������βָ��ͬһ��(�׽ڵ�)�������Ϊ��
	if (queue->eFront == queue->eRear)
		return true;
	else
		return false;
}

void eTraverseLinkQueue(eEmergency queue)
{
	enode queNode = NULL;//���ָ��

	if (eIsEmptyLinkQueue(queue))
	{
		printf("����Ϊ��\r\n");
		return;
	}

	cout << "                                                          ��ǰ����������Ա���������ң�: ";
	queNode = queue->eFront->Enext;//��һ����Ч���
	while (queNode != NULL)//���һ��������
	{
		printf("%d ", queNode->Edat);//�������
		queNode = queNode->Enext;//��һ�����
	}
	printf("\r\n");
}

void eOutLinkQueue(eEmergency queue, int* value)
{
	enode queNode = 0;//���н��ָ��

	if (eIsEmptyLinkQueue(queue))
	{
		printf("ȱʧ����\r\n");
		*value = 0;
		return;
	}

	if (queue->eFront->Enext == queue->eRear)//ֻ��һ����Ч���
		queue->eRear = queue->eFront;//��βָ����ڶ���ָ��

	queNode = queue->eFront->Enext;//���ָ��ָ�������Ч���
	queue->eFront->Enext = queNode->Enext;//���׽��ָ��ָ���¸����
	*value = queNode->Edat;//���ӽ��ֵ
	free(queNode);//�ͷ��ڴ�

	cout << "                                                          ��ǰ���������ߺ��룺" << *value;
	cout << "                                                          ��Ҫ���������������������1����";
}

int eCountLinkQueue(eEmergency queue)
{
	enode queNode = NULL;//���ָ��
	int len = 0;

	if (eIsEmptyLinkQueue(queue))
	{
		printf("��ʽ����Ϊ��......\r\n");
		return len;
	}

	queNode = queue->eFront->Enext;//��һ����Ч���
	while (queNode != NULL)//���һ��������
	{
		len++;
		queNode = queNode->Enext;//��һ�����
	}

	printf("                                                          ������������: %d\r\n", len);
	return len;
}

int main() {
	nNormal N;
	eEmergency E;
	N = nCreatLinkQueue();//������ʽ����
	E = eCreatLinkQueue();
	int ndelVal = 0;
	int edelVal = 0;
	while (true) {
		system("cls");
		cout << "                                                               1��������ͨ������Ϣ����ͨ���                \n";
		cout << "                                                               2���������������Ϣ���������                \n";
		cout << "                                                               3���鿴��ǰ��ͨ�����Ŷ������뵱ǰ������\n";
		cout << "                                                               4���鿴��ǰ���������Ŷ������뵱ǰ������\n";
		cout << "                                                               5���˳�����                                                        \n";
		cout << "                                                              �������������";
		int kind;
		cin >> kind;
		cout << "-----------------------------------------------------------------------------------------------------------------\n";
		switch (kind) {
		case 1: {
			cout << "                                                          ��������ͨ���ﲡ�˺��룺";
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
				cout << "                                                      ������������ﲡ�˺��룺";
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