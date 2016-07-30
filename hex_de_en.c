#include <stdio.h>
const int FILE_LEN = 100;
const int LEN = 10000;
void hex_en();
void hex_de();

int main(){
	int choice = 0;
	printf("十六进制加密请输入1,解密请输入0\n");
	scanf("%d",&choice);
	getchar();   //这里给了一个回车
	if(choice){
		//加密
		hex_en();
	}else{
		//解密
		hex_de();
	}
	return 0;
}

void hex_de(){
	char input[LEN] = "";
	printf("输入十六进制字符,结尾输入0A表示输入结束\n");
	char ch;
	int cnt = 0;
	scanf("%hhx",&ch);
	while(ch!='\n'){
		input[cnt++] = ch;
		scanf("%hhx",&ch);
	}
	puts(input);
	cnt = 0;
	unsigned char key = 0x00;
	char output[LEN] ="";
	while(cnt < 255){
		for (int i = 0; input[i]!=0 ; ++i)
		{
			output[i] = input[i] ^ key;
		}
		puts(output);
		key++;
		cnt++;
	}
}

void hex_en(){
	//十六进制输出加密结果
	char input[LEN] = "";
	printf("输入要加密的字符串\n");
	char ch;
	int cnt = 0;
	while((ch=getchar()) != '\n'){
		input[cnt++] = ch;
	}
	printf("输入加密密钥\n");
	unsigned char key;
	scanf("%hhi",&key);
	printf("你输入的密钥是%hhx",key);
	char output[LEN] ="";
	for (int i = 0; input[i]!=0; ++i)
	{
		output[i] = input[i] ^ key;
	}

	printf("加密成功,输出加密结果:\n");
	for (int i = 0; output[i]!=0; ++i)
	{
		printf("%hhx ",output[i]);
	}
	putchar('\n');

}