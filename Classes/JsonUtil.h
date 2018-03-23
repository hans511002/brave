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
	//#�������
	//// ʹ���������������ʣ�����֮�໹����Ч��
	//const Value& a = document["a"];
	//assert(a.IsArray());
	//for (SizeType i = 0; i < a.Size(); i++) // ʹ�� SizeType ������ size_t
	//	printf("a[%d] = %d\n", i, a[i].GetInt());

	//�ı� Value ����
	//Document d; // Null
	//d.SetObject();
	//Value v;    // Null
	//v.SetInt(10);
	//v = 10;     // ��д�����������ͬ
	//Value b(true);    // ���� Value(bool)
	//Value i(-123);    // ���� Value(int)
	//Value u(123u);    // ���� Value(unsigned)
	//Value d(1.5);     // ���� Value(double)

	//Ҫ�ؽ��� Object �� Array������Ĭ�Ϲ��캯����ʹ�� SetObject() / SetArray()����һ����ʹ�� Value(Type)��
	//Value o(kObjectType);
	//Value a(kArrayType);
	//Value a(kArrayType);

	// ���ݶ���ת��
	//Document::AllocatorType& allocator = document.GetAllocator();
	//// a.PushBack(Value(42), allocator);       // ����ͨ������
	//a.PushBack(Value().SetInt(42), allocator); // fluent API
	//a.PushBack(Value(42).Move(), allocator);   // ����һ����ͬ



	//###string##
	//const char * cstr = getenv("USER");
	//size_t cstr_len = ...;                 // ����г���
	//Value s;
	//// s.SetString(cstr);                  // �ⲻ��ͨ������
	//s.SetString(StringRef(cstr));          // ���ԣ����������������ڰ�ȫ���������Կ��ַ���β��
	//s = StringRef(cstr);                   // ���е���д
	//s.SetString(StringRef(cstr, cstr_len));// ���죬�ɴ�����ַ�
	//s = StringRef(cstr, cstr_len);         // ���е���д

	//##�޸� Array################################################################
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
	//	a.PushBack(i, allocator);   // ������Ҫ���� realloc() ������Ҫ allocator
	//// �����ӿڣ�Fluent interface��
	//a.PushBack("Lua", allocator).PushBack("Mio", allocator);

	//// �͵� Value ����
	//contact.PushBack(Value("copy", document.GetAllocator()).Move(), // copy string
	//	document.GetAllocator());
	//// ��ʽ Value ����
	//Value val("key", document.GetAllocator()); // copy string
	//contact.PushBack(val, document.GetAllocator());

	//################################�޸� Object########################
	//Value& AddMember(Value&, Value&, Allocator& allocator)
	//Value& AddMember(StringRefType, Value&, Allocator&)
	//template <typename T> Value& AddMember(StringRefType, T value, Allocator&)

	//exp:
	//Value contact(kObject);
	//contact.AddMember("name", "Milo", document.GetAllocator());
	//contact.AddMember("married", true, document.GetAllocator());
	//// �͵� Value ����
	//contact.AddMember(Value("copy", document.GetAllocator()).Move(), // copy string
	//	Value().Move(),                                // null value
	//	document.GetAllocator());
	//// ��ʽ����
	//Value key("key", document.GetAllocator()); // copy string name
	//Value val(42);                             // ĳ Value
	//contact.AddMember(key, val, document.GetAllocator());

	//�Ƴ���Ա�м���ѡ��
	//bool RemoveMember(const Ch* name)��ʹ�ü������Ƴ���Ա������ʱ�临�Ӷȣ���
	//bool RemoveMember(const Value& name)������ name ��һ�� Value������һ����ͬ��
	//MemberIterator RemoveMember(MemberIterator)��ʹ�õ������Ƴ���Ա��_ ���� _ ʱ�临�Ӷȣ���
	//MemberIterator EraseMember(MemberIterator)�����������Ƶ�ά�ֳ�Ա��������ʱ�临�Ӷȣ���
	//MemberIterator EraseMember(MemberIterator first, MemberIterator last)���Ƴ�һ����Χ�ڵĳ�Ա��ά�ִ�������ʱ�临�Ӷȣ���

	//����Value
	//Document d;
	//Document::AllocatorType& a = d.GetAllocator();
	//Value v1("foo");
	//// Value v2(v1); // ������
	//Value v2(v1, a);                      // ����һ����¡
	//assert(v1.IsString());                // v1 ����
	//d.SetArray().PushBack(v1, a).PushBack(v2, a);
	//assert(v1.IsNull() && v2.IsNull());   // ������ת�ƶ� d
	//v2.CopyFrom(d, a);                    // ������ document ������ v2
	//assert(d.IsArray() && d.Size() == 2); // d ����
	//v1.SetObject().AddMember("array", v2, a);
	//d.PushBack(v1, a);

	//���� Value
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
	//����
	bool getBoolValue(Value *node, string namePath, int idx);
	int getIntValue(Value *node, string namePath, int idx);
	long long getLLongValue(Value *node, string namePath, int idx);
	double getDoubleValue(Value *node, string namePath, int idx);
	string getStringValue(Value *node, string namePath, int idx);
	const char * getCharsValue(Value *node, string namePath, int idx);

	//��������.,δ�����ͼ��
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

