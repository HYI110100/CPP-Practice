#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
	cout << "尝试输入: \'Hello World\'" << endl;
	string InputValuev;
	while (true) {
		getline(cin,InputValuev);
		cout << "调试: 你输入了 \"" << InputValuev << "\"" << endl;
		if (InputValuev == "Hello World")
		{
			cout << "输出成功！你输入的是:" << InputValuev << endl;
		}
		else
		{
			cout << "输入错误！在试试" << endl;
		}
	}
}

/*
 * 实战踩坑记录
 *
 * 1. 中文标点导致的编译错误
 *
 * 问题现象：
 *   编译时报错："常量中有换行符" 和 "缺少';'(在'}'的前面)"
 *
 * 原因分析：
 *   - 中文标点（如！，。）在UTF-8编码中占用3个字节
 *   - 编译器解析时可能将多字节字符的最后一个字节误判为特殊符号
 *   - 导致编译器认为字符串未正常结束
 *
 * 例子：
 *   ❌ cout << "错误！" << endl;  // 编译错误
 *   ✅ cout << "错误!" << endl;   // 编译通过
 *
 *
 * 2. cin >> 无法读取带空格的字符串
 *
 * 问题现象：
 *   输入 "Hello World" 时，只读取到 "Hello"
 *   第二次递归调用时自动读取到 "World"
 *
 * 原因分析：
 *   - cin >> 以空白字符（空格、制表符、换行）作为分隔符
 *   - 遇到空格就停止读取，剩余内容留在缓冲区
 *
 * 解决方案：
 *   使用 getline(cin, string) 整行读取替代 cin >>
 *
 * 例子：
 *   ❌ cin >> input;        // 只能读取单个单词
 *   ✅ getline(cin, input);  // 可以读取整行，包括空格
 */