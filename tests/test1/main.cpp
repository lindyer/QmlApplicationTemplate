#include <AppBase>
#include "Email.h"

#include <QDebug>
#include <QTimer>

int main(int argc, char *argv[]){
    qSetMessagePattern("%{type} %{time [MM/dd hh:mm:ss.zzz]} %{file}(%{function})[%{line}]-> %{message} ");
    AppInstance::initFn = [](AppType &app,WindowManager &wm) {
        //set app version number
        AppVersion::setVersion(0,0,1,AppVersion::Alpha);

        //set something info about app
        app.setApplicationName("QmlApplicationiTemplate");

        //register your type into meta object system
        qmlRegisterType<Email>("MyTypes",1,0,"Email");

        //wm.addImportPath("./plugins");

        //you add context property before push qml document
        wm.rootContext()->setContextProperty("email",new Email("linjianpengwork@gmail.com","linjianpeng"));

        //push qml document
        wm.push(QUrl("qrc:/main.qml"));

        //replace main.qml with OtherWindow.qml
        QTimer::singleShot(2000,[&wm](){
            wm.replace(QUrl("qrc:/OtherWindow.qml"));
        });
    };
    return AppInstance::run(argc,argv);
}
