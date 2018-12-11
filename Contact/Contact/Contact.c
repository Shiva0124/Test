#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"

int FindSign(const Contact* con,char* name)
{
	int i = 0;

	for (i = 0; i < con->sz; i++)
	{
		if (strcmp(con->data[i].name,name) == 0)
		{
			return i;
		}
	}

	return -1;

}

void Init(Contact* con)
{
	//���ٶ�̬�ڴ�ռ�
	PeoInfo* ptr = (PeoInfo*)malloc(2 * sizeof(PeoInfo));
	if (ptr == NULL)
	{
		printf("%s\n", strerror(errno));
		return;
	}
	con->data = ptr;

	//��ʼ���ṹ������
	memset(con->data, 0,sizeof(con->data));
	//��ʼ��ͨѶ¼����
	con->sz = 0;
	//��ʼ������
	con->capacity = 2;
}

void AddContact(Contact* con)
{
	assert(con != NULL);
	//�ж϶�̬�ڴ��Ƿ���
	if (con->sz == con->capacity)
	{
		//relloc void* ��Ҫ��ָ�����
		//relloc()�У��ڶ����������µ��ڴ�ռ�
		PeoInfo *ptr = realloc(con->data, (con->capacity+2) * sizeof(PeoInfo));
		if (ptr == NULL)
		{
			printf("%s\n", strerror(errno));
			return;
		}
		else
		{
			con->data = ptr;
			con->capacity += 2;
			printf("���ݳɹ���\n");
		}
	}

	//������Ϣ
	printf("����������:>");
	scanf("%s", &(con->data[con->sz].name));
	
	printf("�������Ա�:>");
	scanf("%s", &(con->data[con->sz].sex));

	printf("����������:>");
	scanf("%d", &(con->data[con->sz].age));

	printf("������绰:>");
	scanf("%s", &(con->data[con->sz].tele));

	printf("�������ַ:>");
	scanf("%s", &(con->data[con->sz].addr));

	con->sz++;

	
		
	printf("���ӳɹ���\n");

}

void DelContact(Contact* con)
{

	char name[MAX_NAME] = { 0 };
	int pos = 0;
	int j = 0;
	
	assert(con != NULL);

	printf("������Ҫɾ��������:>");
	scanf("%s", &name);

	pos = FindSign(con, name);

	if (-1 == pos)
	{
		printf("û����Ҫɾ������Ϣ\n");
		return;
	}
	else
	{
		for (j = pos; j < con->sz - 1; j++)
		{
			con->data[j] = con->data[j + 1];
		}
		con->sz--;
		printf("ɾ���ɹ���\n");
	}
}

void ShowContact(const Contact* con)
{
	int i = 0;
	printf("%10s\t%5s\t%5s\t%12s\t%20s\n","����","�Ա�","����","�绰","��ַ");
	for (i = 0; i < con->sz; i++)
	{
		printf("%10s\t%5s\t%5d\t%12s\t%20s\n", con->data[i].name, con->data[i].sex, con->data[i].age, con->data[i].tele, con->data[i].addr);

	}
}

void SearchContact(const Contact* con)
{
	char name[MAX_NAME] = { 0 };
	int pos = 0;

	assert(con != NULL);

	printf("������Ҫ���ҵ�����:>");
	scanf("%s", &name);

	pos = FindSign(con, name);

	if (-1 == pos)
	{
		printf("û����Ҫ���ҵ���Ϣ\n");
		return;
	}
	else
	{
		printf("%10s\t%5s\t%5s\t%12s\t%20s\n", "����", "�Ա�", "����", "�绰", "��ַ");
		
		printf("%10s\t%5s\t%5d\t%12s\t%20s\n", con->data[pos].name, con->data[pos].sex, con->data[pos].age, con->data[pos].tele, con->data[pos].addr);

	}
}

void ChangeContact(Contact* con)
{
	char name[MAX_NAME] = { 0 };
	int pos = 0;

	assert(con != NULL);

	printf("������Ҫ�޸�����Ϣ������:>");
	scanf("%s", &name);

	pos = FindSign(con, name);

	if (-1 == pos)
	{
		printf("û���ҵ���Ҫ�޸ĵ���Ϣ\n");
		return;
	}
	else
	{
		printf("����������:>");
		scanf("%s", &(con->data[pos].name));

		printf("�������Ա�:>");
		scanf("%s", &(con->data[pos].sex));

		printf("����������:>");
		scanf("%d", &(con->data[pos].age));

		printf("������绰:>");
		scanf("%s", &(con->data[pos].tele));

		printf("�������ַ:>");
		scanf("%s", &(con->data[pos].addr));

		printf("�޸ĳɹ���\n");
	}
}


void SortContact(Contact* con)
{
	int i = 0;
	int j = 0;
	int flag = 1;
	PeoInfo tmp;
	for (i = 0; i < con->sz; i++)
	{
		for (j = 0; j < con->sz - i - 1; j++)
		{
			if (con->data[j].name < con->data[j+1].name)
			{
				tmp = con->data[j];
				con->data[j] = con->data[j + 1];
				con->data[j + 1] = tmp;
				flag = 0;
			}
			if (flag == 1)
			{
				return;
			}
		}
	}
	printf("����ɹ���\n");

}

//void free(Contact* con)
//{
//	free(con->data);
//	con->data = NULL;
//}