#ifndef LEPTJSON_H__
#define LEPTJSON_H__


//[ ]: 更方便的保存数据
//[ ]: 这里的每一个成员都是代表的解析到的数据类型是啥？！
typedef enum { LEPT_NULL, LEPT_FALSE, LEPT_TRUE, LEPT_NUMBER, LEPT_STRING, LEPT_ARRAY, LEPT_OBJECT } 
lept_type;

typedef struct {
    lept_type type;
}lept_value;

enum {
    LEPT_PARSE_OK = 0,
    //[ ]: 下面这个代表解析的json只有空白！
    LEPT_PARSE_EXPECT_VALUE,
    //[ ]: 传回来的是不是我们需要的三种数值
    LEPT_PARSE_INVALID_VALUE,
    //[ ]: 空白字符后面还有字符
    LEPT_PARSE_ROOT_NOT_SINGULAR
};
//[ ]: 输入参数的前者是解析后返回值，后者则是需要解析的数据
int lept_parse(lept_value* v, const char* json);

//[ ]: 通过 left_parse 函数获取到的结果进行访问结果
lept_type lept_get_type(const lept_value* v);

#endif /* LEPTJSON_H__ */
