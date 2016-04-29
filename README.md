##极验验证c++客户端demo

基于QT, 欢迎贡献

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