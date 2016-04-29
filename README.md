##极验验证c++客户端demo

**特备感谢 @xh286286 用户的贡献**

基于QT

因人力有限, 无法持续维护c++客户端, 欢迎贡献

仅供参考, 不保证能正常流程

调用实例, 每次验证需要单独创建一次实例

```
GeeTestView * geetestView = nullptr;
geetestView = new GeeTestView(ui.widget_geetest);
geetestView->loadGeeTest();
geetestView->show();
QObject::connect(geetestView, &GeeTestView::gtResultSended, [this](QString result){
		//API2

});
```

id请在官网注册申请[官网](www.geetest.com)

服务端sdk集成开发见[官网安装中心](http://www.geetest.com/install/)

**关于本地客户端开发详细流程见根目录下的*workflow.md*文件.**