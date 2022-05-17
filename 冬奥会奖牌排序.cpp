#include<stdio.h>
#include<string.h>

struct sut
{
	char nation[100];//����
	int goldNumber;  //������
	int silverNumber;//������
	int bronzeNumber;//ͭ����
	int sum;         //����
};
int main()
{
	struct sut a[100] = {'\0'};
	struct sut *pa = a;
	char str[9][100] = { '\0' };
	int i;
	FILE *fp = fopen("D:\\C\\file.txt", "r");
	if (fp == NULL)
	{
		printf("Error\n");
		return 0;
	}
	
	while (fscanf(fp, "%s %d %d %d %d", pa->nation, &pa->goldNumber, &pa->silverNumber, &pa->bronzeNumber, &pa->sum) != EOF)
	{
		printf("%-12s%-8d%-8d%-8d%-8d\n", pa->nation, pa->goldNumber, pa->silverNumber, pa->bronzeNumber, pa->sum);
		pa++;
	}
	fclose(fp);
	
	struct sut t;
	for (i = 0; i < 8; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (a[j].sum > a[j + 1].sum)
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}

	
	printf("\n\n");
	FILE *max = fopen("D:\\VS2015\\now1.txt", "w");    //�ļ�ָ�루���������Ĺ��ң�
	FILE *min = fopen("D:\\VS2015\\now2.txt", "w");    //�ļ�ָ�루���������ٵĹ��ң�
	fprintf(max, "%-12s%-8d%-8d%-8d%-8d\n", a[7].nation, a[7].goldNumber, a[7].silverNumber, a[7].bronzeNumber, a[7].sum); //�����������Ĺ���д���ļ�now1.txt��
	fprintf(min, "%-12s%-8d%-8d%-8d%-8d\n", a[0].nation, a[0].goldNumber, a[0].silverNumber, a[0].bronzeNumber, a[0].sum); //�����������ٵĹ���д���ļ�now2.txt��
	fclose(max); //�ر��ļ�
	fclose(min);
	

	printf("---���������Ĺ�����:%-12s ����:%-8d ����:%-8d ͭ��:%-8d ������:%-8d---\n"
		, a[7].nation, a[7].goldNumber, a[7].silverNumber, a[7].bronzeNumber, a[7].sum);  //��ӡ���������Ĺ��ҵ���Ļ
	printf("---���������ٵĹ�����:%-12s ����:%-8d ����:%-8d ͭ��:%-8d ������:%-8d---\n"   //��ӡ���������ٵĹ��ҵ���Ļ
		, a[0].nation, a[0].goldNumber, a[0].silverNumber, a[0].bronzeNumber, a[0].sum);


	for (i = 0; i < 8; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (a[j].goldNumber > a[j + 1].goldNumber)
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}

	FILE *wfp = fopen("D:\\VS2015\\file_sorted.txt", "w");  //���ս��ƽ��������������������������� file_sorted.txt
	for (i = 0; i<8; i++)
	{
		fprintf(wfp, "%-12s%-8d%-8d%-8d%-8d\n", a[i].nation, a[i].goldNumber, a[i].silverNumber, a[i].bronzeNumber, a[i].sum);
	}
	fclose(wfp);//�ر��ļ�
	return 0;
}