##极验验证c++客户端demo

基于QT, 欢迎贡献

仅供参考, 不保证能正常流程


GeeTestView * geetestView = nullptr;
geetestView = new GeeTestView(ui.widget_geetest);
geetestView->loadGeeTest();
geetestView->show();
QObject::connect(geetestView, &GeeTestView::gtResultSended, [this](QString result){
		//API2

});