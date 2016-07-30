#include <stdio.h>
#include <string.h>
const int LEN = 10000;
const int FILE_LEN = 100;
const size_t size_of = sizeof(char);
void print_in(const char* output);
void read_in(char* input, char* filename);
void encryption();

int main(){
	//字符串加密,fprint写出
	//文本加密,fprint写出
	encryption();
	return 0;
}

void encryption(){
	char input[LEN]="";
	char output[LEN] = "";
	int is_File = 0;
	printf("加密文件输入1,加密字符串输入0\n");
	scanf("%d",&is_File);
	getchar();
	char filename[FILE_LEN]="";
	if(is_File){
		read_in(input,filename);	//读入文件内容
	}else{
		printf("请输入要加密的字符串,结束输入\n");
		int cnt = 0;
		char ch;
		while((ch=getchar())!='\n'){
			input[cnt++] = ch;
		}
		printf("你输入的字符串是%s\n",input);
	}

	unsigned char key;
	printf("输入2位十六进制加密密钥\n");
	scanf("%hhi",&key);
	printf("你输入的加密密钥是%hhx\n",key);
	for (int i = 0; input[i]!=0; ++i)
	{
		output[i] = input[i] ^ key;
	}
	printf("加密成功\n");

	print_in(output);

}

void print_in(const char* output){
	printf("请输入要写入的文件名:\n");
	size_t ret = 0 ;
	char filename[FILE_LEN] = "";
	scanf("%s",filename);
	FILE *fp = fopen(filename,"w");
	size_t write_len = strlen(output);
	ret = fprintf(fp,"%s",output);
	if(ret == write_len)
		printf("写入成功\n");
	fclose(fp);
}

void read_in(char* input, char* filename){
	printf("请输入要读入的文件名:\n");
	scanf("%s",filename);
	FILE *fp = fopen(filename,"r");
	size_t file_len;
	size_t read_len;

	fseek(fp,0L,SEEK_END);
	file_len = ftell(fp);
	fseek(fp,0L,SEEK_SET);

	read_len = fread(input,size_of,file_len,fp);
	if(read_len == file_len)
		printf("读入成功\n");
	fclose(fp);
}

