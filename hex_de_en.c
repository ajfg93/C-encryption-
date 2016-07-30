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
	unsigned char key;
	printf("输入十六进制字符,结尾输入0A表示输入结束\n");
	char ch;
	int cnt = 0;
	scanf("%hhx",&ch);
	while(ch!='\n'){
		input[cnt++] = ch;
		scanf("%hhx",&ch);
	}
	int has_key = 0;
	printf("有密钥输入1,无密钥输入0\n");
	scanf("%d",&has_key);
	if(has_key){
		printf("输入你的密钥\n");
		scanf("%hhi",&key);
		printf("你输入的密钥是%hhx\n",key);
	}else{
		key = 0x00;
	}
	cnt = 0;
	char output[LEN] ="";
	printf("解密的结果:\n");
	while(cnt < 255){
		for (int i = 0; input[i]!=0 ; ++i)
		{
			output[i] = input[i] ^ key;
		}
		puts(output);
		if(has_key)
			break;
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
	printf("加密前的十六进制结果是:\n");
	for (int i = 0; input[i]!=0; ++i)
	{
		printf("%hhx ",input[i]);
	}
	putchar('\n');
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