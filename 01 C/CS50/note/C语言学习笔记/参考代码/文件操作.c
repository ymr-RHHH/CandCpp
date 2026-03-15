#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//文件操作基本流程 
//	定义文件指针
//	打开文件
//	操作文件
//	关闭文件

int main()
{
	// 定义文件指针
	// C语言中，就指针可以用来直接访问内存，而在标准库中这些都已经为你准备了，直接用就行
	FILE* fp1;
	// 直接定义个指针变量，一会儿用于来保存文件的地址

	// 使用fopen函数打开文件，并将其地址存到fp1中。
	fp1 = fopen("111.txt", "w");  //w以只写的形式打开文件，若出错会返回一个空指针,正常来讲会返回文件首地址
	if (fp1 == NULL)
	{
		printf("悲催！又报错了！\n");
		return  EOF;
	}
	else
	{
		printf("文件打开成功！\n");
	}


	// 然后就是对文件进行操作了

	// 比如说写入一个字符到该文件：
	char a = 'a';
	printf("%c", fputc(a, fp1));

	// 可以用这个向文件写入一个字符转
	char ch[] = "ymr";
	printf("1:");
	for (int i = 0; i < (sizeof(ch)); i++)
	{
		printf("%c", fputc(ch[i], fp1));
	}  //由于是以只写的方式打开，所以每次打卡都会重新清空文件。

	// 每次干完活记得把文件关了，一来防止文件被下面操作误伤；二来便于后续操作。
	fclose(fp1);

	// 从文件中读取数据
	fp1 = fopen("111.txt", "r"); // 读取数据时要以只读或者读写的形式打开，否则会在读取时精神错乱
	char c;
	printf("2:");
	while ((c = fgetc(fp1)) != EOF) {
		printf("%c", c);
	}
	fclose(fp1);
	printf("\n");


	// 还可以直接读、写入字符串（使用fputs()、fgets()）
	FILE* fp2;
	fp2 = fopen("111.c", "w");
	if (fp2 == NULL)
	{
		printf("悲催！又报错了！\n");
		return  EOF;
	}
	else
	{
		printf("文件打开成功！\n");
	}
	fputs("yuanmourenzuishuai!\n", fp2);
	fclose(fp2);

	char text[100];
	fp2 = fopen("111.c", "r");
	printf("%s", fgets(text, 100, fp2));
	fclose(fp2);

	// C语言中，有printf()函数，用于向控制台输出字符，其本质是向输出流写入数据
	//          有scanf()函数，用于从缓冲区向输入流读取字符

	// 同理，就有fprintf()函数，向文件中写入数据
	//           fscanf()函数，从文件中读取数据
	FILE* fp;
	fp = fopen("file.txt", "w"); // 打开文件
	// 将数据写入文件
	fprintf(fp, "袁某人最帅！！！！！\n");
	fclose(fp);

	char buff[255]; // 创建char数组存储文件数据
	fp = fopen("file.txt", "r");
	while (fscanf(fp, "%s", buff) != EOF) {
		printf("%s ", buff);
	}
	fclose(fp);

	// 要知道一件事情：
	// 文件指针打开文件后默认指向文件的开头，也就是第一个数据的位置，
	// 此后每一次读取或写入，文件指针自动向后
	// 移动到与数据大小对应文件位置

	// 可以用rewind()函数强行将光标移到开头处
	printf("\n------------------\n");
	fp = fopen("file.txt", "r");
	while ((c = fgetc(fp)) != EOF) {
		printf("%c", c);
	}
	rewind(fp); // 将文件指针移动到文件的开头,这样就可以重复读取了
	while ((c = fgetc(fp)) != EOF) {
		printf("%c", c);
	}
	fclose(fp);

	// 可以用fseek()实现将光标移到任意位置
	fp = fopen("myfile.txt", "w+");
	fputs("This is Book", fp);
	// 将文件指针设置到给定位置
	fseek(fp, 7, SEEK_SET);     //没有这句话文件中就是 This is BookKenny Wong
	fputs("Kenny Wong", fp);    //有就是               This isKenny Wong 
	fclose(fp);


}
