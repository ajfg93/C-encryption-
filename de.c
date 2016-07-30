#include <stdio.h>
#include <string.h>
const int LEN = 10000;
const int FILE_LEN = 100;
const size_t size_of = sizeof(char);
void read_in(char* input, char* filename);
void decryption();

int main(){
	//文件解密,fread读入,然后fprint写出,有密钥会在终端输入,无密钥终端不输出
	//是否有密钥

	decryption();
	return 0;
}

void decryption(){
	char input[LEN]="";
	char filename[FILE_LEN]="";
	read_in(input,filename);
	{
		puts(input);
		getchar();
	}
	// char *init_filename = strcat(filename,"");  //将原来的文件名保存下来
	char *output_filename = strcat(filename,".de");
	FILE *fp = fopen(output_filename,"a");
	int has_key;
	unsigned char key;
	printf("有密钥请按1,无密钥请按0\n");
	scanf("%d",&has_key);
	if(has_key){
		printf("输入解密密钥\n");
		scanf("%hhi",&key);
	}else{
		printf("没有密钥,将自动解密\n");
		key = 0x00;
	}
	int cnt = 0;
	while(cnt <= 255 ){
		char output[LEN]="";
		for (int i = 0; input[i]!=0; ++i)
		{
			output[i] = input[i]^key;
		}
		fprintf(fp,"%s\n<==========Boundary============>\n",output);
		if(has_key){
			printf("解密后的字符串是:%s\n",output);
			break;
		}
		key++;
		cnt++;
	}
	printf("解密内容保存在=>%s\n", output_filename);
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
