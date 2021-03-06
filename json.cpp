引自：https://blog.csdn.net/yc461515457/article/details/52749575/
Json::Value
使用Json::Value用来表示Json中的任何一种value抽象数据类型，具体有：signed integer [range:Value::miniInt - Value::maxInt]
unsiged integer(range:0-Value::maxUint);double,string,bool,null,
通过[]的方法进行取值。

Json::Reader
假设现在有一个example.json文件：
      {
          “encoding”:"UTF-8",
          "plug-ins":[
          "python",
          "c++",
          "ruby"
          ],
          "indent":{"lengh":3,"use_space":true}
          
      }
使用Json::Reader对json文件进行解析：
    函数原型：
    bool parse(const std::string $document,Value &root, bool collectComments=true)
    bool parse(const std::isstream $is, Value $root, bool coolectComments=true)
    
    应用：
    Json::Value root;
    Json::Reader reader;
    std::ifstream ifs("example.json")；//open file example.json
    
    if(!reader.parse(ifs,root)){
      //fail to parse
     }
     
     else{
     //success
     std::cout<<root["encoding"].asString()<<endl;
     std::cout<<root["indent"]["length"].asInt()<<endl;
     }
     
使用Json::Reader对字符串进行解析
     bool Json::Reader::parse(const char *beginDoc,
                              const char * endDoc,
                              Value & root,
                              bool collectComments = true
     )
     
     Json::Value root;
     Json：：Reader reader;
     const char* s = "{\"up;oadid\":\"UP0000\",\"code\":100,\"msg\";\"\",}"
     if(!reader.parse(s,root)){
        //“parse fail”
     }
     else{
     std::cout<<root["uploadid"].asString();//print"UP00000"
     }
     
  使用Json::Writer
     Json::writer和Json::Reader相反，是把Json::Value对象写到string对象中，而且Json::Writer是个抽象类，被两个子类Json::FasterWrite和Json::StyledWriter继承。
     简单的来说fastWriter就是无格式的写入，这样的Json看起来很乱，没有格式，而且StyledWriter就是带有格式的写入，看起来会比较友好。
     
     Json::Value      root;
     Json::Reader     reader;
     Json::FastWriter fwiter;
     Json::StyleWriter swriter;
     
     if(!read.parse("example.json",root))
     {
         //psrse fsil
         return 0;
     }
     
     std::string str = fwriter(root);
     std::ofstream ofs("example_fast_writer.json");
     ofs<<str;
     ofs.close();
     
     str = swriter(root);
     ofs.open("example_stryled_writer.json");
     ofs<<str;
     ofs.close();
     结果：
     example——styled——writerjson
     {
            "encoding":"UTF-8",
            "plug-ins":[
            “python”,
            "c++",
            "ruby"
            ],
            "indent" : {"length":3,"use_space":true}    
     }
     
     example_styled_writer.json
     { "encoding" : "UTF-8", "plug-ins":["python","c++","ruby"],"indent":{"length":3,"use_space":true}}
     
判断Value是否为null
     首先给example.json添加一个key-value对：
         {
            "encoding":"UTF-8",
            "plug-ins":[
            “python”,
            "c++",
            "ruby"
            ],
            "indent" : {"length":3,"use_space":true}    
            “tab-length”:[],
            "tab":null
     }
     
     f(root["tab"].isNull())
     {
     std::cout << "isNull" <<std::endl;//print isNull
     }
     

Value:: isNull() / isBool() / isInt() / isDouble() / isString() / isArray() / isObject() etc..
判断Json节点对象类型：JsonRoot[node].isInt()

Value:: asString() / asInt() / asDouble / asBool()
将Json数据转为对应类型

