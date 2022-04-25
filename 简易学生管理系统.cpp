#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
int iCount;
struct student
{
	int stuID;                      //ѧ��ѧ��
	char Name[100];                 //ѧ������
	char Remove[100];               //ѧ���༶

	struct student *next;           //�����һ���ڵ�ĵ�ַ
};
struct student* create()            //���뺯��
{
	char str1;
	struct student* pHead = NULL;  //��ʼ������ʹͷָ��Ϊ��
	struct student* pNew, *pEnd;   //pNewָ���´����Ľ�㣬pEndָ��ԭ����β���
	iCount = 0;                    //��ʼ��������
	pEnd = pNew = (struct student*)malloc(sizeof(struct student));//��̬����һ���ڴ�ռ�

	printf("������ѧ������:");      //����ѧ����Ϣ
	scanf("%s", &pNew->Name);
	getchar();
	printf("������ѧ��ѧ��:");
	scanf("%d", &pNew->stuID);
	printf("������ѧ���༶:");
	scanf("%s", &pNew->Remove);
	getchar();

	pNew->next = pHead;
	pEnd = pNew;
	pHead = pNew;
	iCount++;

	printf("�Ƿ��������y/n:");
	scanf("%c", &str1);
	printf("\n");

	while (str1!='n')
	{
		iCount++;                       //�������1
		pNew = (struct student*)malloc(sizeof(struct student));//��̬����һ���ڴ�ռ�
		printf("������ѧ������:");      //����ѧ����Ϣ
		scanf("%s", &pNew->Name);
		getchar();
		printf("������ѧ��ѧ��:");
		scanf("%d", &pNew->stuID);
		printf("������ѧ���༶:");
		scanf("%s", &pNew->Remove);
		getchar();

		pNew->next = NULL;
		pEnd->next = pNew;
		pEnd = pNew;

		printf("�Ƿ��������y/n:");
		scanf("%c", &str1);
		printf("\n");
	}
	return pHead;
}


void Print(struct student* pHead)  //�������
{
	struct student *pTemp;
	int iIndex = 1;

	printf("the List has %d members:----\n", iCount);
	printf("\n");
	pTemp = pHead;

	while (pTemp != NULL)
	{
		printf("�༶:%-15s ����:%-10s ѧ��:%-10d\n", pTemp->Remove, pTemp->Name, pTemp->stuID);
		pTemp = pTemp->next;
		iIndex++;
	}
	printf("\n");

}

void _delete(struct student* pHead)     //ɾ������
{
	int id,r=1,i;
	struct student *pTemp;           //��ʱָ��
	struct student *pPre;            //��ʾҪɾ�����ǰ�Ľ��
	pTemp = pHead;                   //�õ�ͷ���
	pPre = pTemp;
	printf("������Ҫɾ��ѧ��");
	scanf("%d", &id);
	getchar();
	while (1)
	{
		
		if ( pTemp->stuID!=id)
		{
			r++;
		}
		else
		{
			pTemp = pHead; break;
		}
		printf("%d\n", r);
		pTemp = pTemp->next;
		
	}
	for (i = 1; i < r; i++)
	{
		pPre = pTemp;
		pTemp = pTemp->next;
	}
	pPre->next = pTemp->next;
	free(pTemp);
	iCount--;
	printf("---ɾ���ɹ�---\n");
}

void find(struct student* pHead)     //��Ϣ��ѯ
{
	int _id,j=0;
	struct student *pTemp;           //��ʱָ��
	pTemp = pHead;
	printf("��������Ҫ��ѯ��ѧ��ѧ�ţ�");
	scanf("%d", &_id);
	while (pTemp->stuID != NULL)
	{
		if (pTemp->stuID == _id)
		{
			printf("�༶:%-15s ����:%-10s ѧ��:%-10d\n\n", pTemp->Remove, pTemp->Name, pTemp->stuID);
			j++;  
			break;
		}
		else if (j == 0)
		{
			printf("---û�в�ѯ����Ϣ---\n\n"); break;
		}
		
		pTemp = pTemp->next;
	}
	


}

int main()
{
	int b;
	struct student* pHead;
	while(1)
	{
		printf("ɾ����Ϣ���� 1\n");
		printf("�����Ϣ���� 2\n");
		printf("�����Ϣ���� 3\n");
		printf("��ѯ��Ϣ���� 4\n");
		scanf("%d", &b);
		getchar();

		switch (b)
		{
		case 1:_delete(pHead);   break;     //ɾ��
		case 2:pHead = create(); break;     //���
		case 3:Print(pHead);     break;     //���
		case 4:find(pHead);      break;     //��ѯ

		}
	}
	
	return 0;
}