# amazeui-customize
amazeui-customize
AmazeUI 云定制服务


<a href="http://www.hyyyp.com/amaze.html" target="_Blank" >hyyyp.com/amaze.html</a>


g++ main.cpp -o thread -lpthread 编译服务端

PHP通过Socket模块 发送MD5随机值与JSON定制内容到达服务端。 
服务端将用MD5随机值作为文件名，将JSON内容写入到文件

JSON文件将写入
amazeui-2.4.2/tools/tasks/config/     
config目录是本人加的
/tools/tasks/customizer.js 增加获取命令行 获取 文件路劲

var test =gulp.env.type;
var test1 =gulp.env.path;

var cstmzPath = path.join(__dirname, '../../dist/'+test);
var configFile = (path.join(__dirname, test1));


C++服务端将json写入
amazeui-2.4.2/tools/tasks/config/MD5.json

将执行
<code>
sprintf(cmd,"/root/node-v0.12.7-linux-x64/bin/gulp customize --type \"%s\" --path ./config/%s.json",name,name);
</code>

gulp customize --type \"MD5\" --path ./config/MD5.json
将构造的目录设定为
amazeui-2.4.2/dist/MD5

通过ZIP压缩 amazeui-2.4.2/dist/MD5  To  MD5.ZIP
随后 将 MD5.ZIP  MV TO  网站服务器 

最终C++服务端Socket将返回On回到PHP 确认成功
PHP跳转URL下载该ZIP压缩包
