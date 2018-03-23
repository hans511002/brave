#ifndef JSON_UTIL_H
#define JSON_UTIL_H
#include "BaseHeaders.h"
#include "common/Common.h"

#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"  
#include "rapidjson/filereadstream.h"  
#include "rapidjson/filewritestream.h"  
#include "rapidjson/stringbuffer.h"
#include "rapidjson/pointer.h"
using namespace std;

#define JsonUtil rapidjson
namespace rapidjson{
	//#数组访问
	//// 使用引用来连续访问，方便之余还更高效。
	//const Value& a = document["a"];
	//assert(a.IsArray());
	//for (SizeType i = 0; i < a.Size(); i++) // 使用 SizeType 而不是 size_t
	//	printf("a[%d] = %d\n", i, a[i].GetInt());

	//改变 Value 类型
	//Document d; // Null
	//d.SetObject();
	//Value v;    // Null
	//v.SetInt(10);
	//v = 10;     // 简写，和上面的相同
	//Value b(true);    // 调用 Value(bool)
	//Value i(-123);    // 调用 Value(int)
	//Value u(123u);    // 调用 Value(unsigned)
	//Value d(1.5);     // 调用 Value(double)

	//要重建空 Object 或 Array，可在默认构造函数后使用 SetObject() / SetArray()，或一次性使用 Value(Type)：
	//Value o(kObjectType);
	//Value a(kArrayType);
	//Value a(kArrayType);

	// 数据对象转移
	//Document::AllocatorType& allocator = document.GetAllocator();
	//// a.PushBack(Value(42), allocator);       // 不能通过编译
	//a.PushBack(Value().SetInt(42), allocator); // fluent API
	//a.PushBack(Value(42).Move(), allocator);   // 和上一行相同



	//###string##
	//const char * cstr = getenv("USER");
	//size_t cstr_len = ...;                 // 如果有长度
	//Value s;
	//// s.SetString(cstr);                  // 这不能通过编译
	//s.SetString(StringRef(cstr));          // 可以，假设它的生命周期安全，并且是以空字符结尾的
	//s = StringRef(cstr);                   // 上行的缩写
	//s.SetString(StringRef(cstr, cstr_len));// 更快，可处理空字符
	//s = StringRef(cstr, cstr_len);         // 上行的缩写

	//##修改 Array################################################################
	//Clear()
	//Reserve(SizeType, Allocator&)
	//Value& PushBack(Value&, Allocator&)
	//template <typename T> GenericValue& PushBack(T, Allocator&)
	//Value& PopBack()
	//ValueIterator Erase(ConstValueIterator pos)
	//ValueIterator Erase(ConstValueIterator first, ConstValueIterator last)

	//exp:
	//Value a(kArrayType);
	//Document::AllocatorType& allocator = document.GetAllocator();
	//for (int i = 5; i <= 10; i++)
	//	a.PushBack(i, allocator);   // 可能需要调用 realloc() 所以需要 allocator
	//// 流畅接口（Fluent interface）
	//a.PushBack("Lua", allocator).PushBack("Mio", allocator);

	//// 就地 Value 参数
	//contact.PushBack(Value("copy", document.GetAllocator()).Move(), // copy string
	//	document.GetAllocator());
	//// 显式 Value 参数
	//Value val("key", document.GetAllocator()); // copy string
	//contact.PushBack(val, document.GetAllocator());

	//################################修改 Object########################
	//Value& AddMember(Value&, Value&, Allocator& allocator)
	//Value& AddMember(StringRefType, Value&, Allocator&)
	//template <typename T> Value& AddMember(StringRefType, T value, Allocator&)

	//exp:
	//Value contact(kObject);
	//contact.AddMember("name", "Milo", document.GetAllocator());
	//contact.AddMember("married", true, document.GetAllocator());
	//// 就地 Value 参数
	//contact.AddMember(Value("copy", document.GetAllocator()).Move(), // copy string
	//	Value().Move(),                                // null value
	//	document.GetAllocator());
	//// 显式参数
	//Value key("key", document.GetAllocator()); // copy string name
	//Value val(42);                             // 某 Value
	//contact.AddMember(key, val, document.GetAllocator());

	//移除成员有几个选择：
	//bool RemoveMember(const Ch* name)：使用键名来移除成员（线性时间复杂度）。
	//bool RemoveMember(const Value& name)：除了 name 是一个 Value，和上一行相同。
	//MemberIterator RemoveMember(MemberIterator)：使用迭代器移除成员（_ 常数 _ 时间复杂度）。
	//MemberIterator EraseMember(MemberIterator)：和上行相似但维持成员次序（线性时间复杂度）。
	//MemberIterator EraseMember(MemberIterator first, MemberIterator last)：移除一个范围内的成员，维持次序（线性时间复杂度）。

	//复制Value
	//Document d;
	//Document::AllocatorType& a = d.GetAllocator();
	//Value v1("foo");
	//// Value v2(v1); // 不容许
	//Value v2(v1, a);                      // 制造一个克隆
	//assert(v1.IsString());                // v1 不变
	//d.SetArray().PushBack(v1, a).PushBack(v2, a);
	//assert(v1.IsNull() && v2.IsNull());   // 两个都转移动 d
	//v2.CopyFrom(d, a);                    // 把整个 document 复制至 v2
	//assert(d.IsArray() && d.Size() == 2); // d 不变
	//v1.SetObject().AddMember("array", v2, a);
	//d.PushBack(v1, a);

	//交换 Value
	//Value a(123);
	//Value b("Hello");
	//a.Swap(b);
	//assert(a.IsString());
	//assert(b.IsInt());



	string toString(Value &node);
	Value * getValue(Value *node, string namePath);


	bool getBool(Value *a);
	int getInt(Value *a);
	long long getLLong(Value *a);
	double getDouble(Value *a);
	string getString(Value *a);
	const char* getChars(Value *a);

	bool getBoolValue(Value *node, string namePath);
	int getIntValue(Value *node, string namePath);
	double getDoubleValue(Value *node, string namePath);
	long long getLLongValue(Value *node, string namePath);
	const char* getCharsValue(Value *node, string namePath);
	string getStringValue(Value *node, string namePath);
	//数组
	bool getBoolValue(Value *node, string namePath, int idx);
	int getIntValue(Value *node, string namePath, int idx);
	long long getLLongValue(Value *node, string namePath, int idx);
	double getDoubleValue(Value *node, string namePath, int idx);
	string getStringValue(Value *node, string namePath, int idx);
	const char * getCharsValue(Value *node, string namePath, int idx);

	//快速设置.,未做类型检查
	template <class T = int> void setValue(Document &doc, string namePath,T val ){
		Common::String tmp = namePath;
		tmp='/'+tmp.ReplaceAll('.', '/');
		JsonUtil::Pointer pt(tmp.c_str());
		//Document::ValueType v = val;
		//JsonUtil::Value & location = CreateValueByPointer(doc, pt);
		//JsonUtil::Value::AllocatorType& a = doc.GetAllocator();
		//SetValueByPointer(location, pt, v,a);
		SetValueByPointer(doc, pt, val);
	};
	template <class T = int> void setValue(Document &doc, string namePath, int idx, T val){
		Common::String tmp = namePath;
		tmp = '/' + tmp.ReplaceAll('.', '/')+'/'+idx; 
		JsonUtil::Pointer pt(tmp.c_str());
		//JsonUtil::Value & location = CreateValueByPointer(doc, pt);
		//JsonUtil::Value::AllocatorType & a = doc.GetAllocator();
		//rapidjson::Value v;
		//v = val;
		//SetValueByPointer(location,pt , v, a);
		SetValueByPointer(doc, pt, val);
	};
	inline bool eraseValue(Document &doc, string namePath){
		Common::String tmp = namePath;
		tmp = '/' + tmp.ReplaceAll('.', '/');
		return EraseValueByPointer(doc, Pointer(tmp.c_str()));
	};
	inline bool eraseValue(Document &doc, string namePath, int idx){
		Common::String tmp = namePath;
		tmp = '/' + tmp.ReplaceAll('.', '/') + '/' + idx;
		return EraseValueByPointer(doc, Pointer(tmp.c_str()));
	};
	//SetValueByPointer(d, "/project", "RapidJSON");
	//SetValueByPointer(d, "/stars", 10);
	//if (Value* stars = GetValueByPointer(d, "/stars"))
	//	stars->SetInt(stars->GetInt() + 1);
	//CreateValueByPointer(d, "/a/b/0");
	//Value& hello = GetValueByPointerWithDefault(d, "/hello", "world");
	//Value x("C++");
	//SwapValueByPointer(d, "/hello", x);
	//bool success = EraseValueByPointer(d, "/a");

}


#endif

