# amazeui-customize
amazeui-customize
AmazeUI 云定制服务


<a href="http://amaze.hyphp.cn/" target="_Blank" >http://amaze.hyphp.cn/</a>


g++ main.cpp -o thread -lpthread 编译服务端 <br>

PHP通过Socket模块 发送MD5随机值与JSON定制内容到达服务端。<br> 
服务端将用MD5随机值作为文件名，将JSON内容写入到文件<br>

JSON文件将写入<br>
amazeui-2.4.2/tools/tasks/config/     <br>
config目录是本人加的 <br>
/tools/tasks/customizer.js 增加获取命令行 获取 文件路劲 <br>

var test =gulp.env.type;<br>
var test1 =gulp.env.path;  <br>

var cstmzPath = path.join(__dirname, '../../dist/'+test);<br>
var configFile = (path.join(__dirname, test1));<br>


C++服务端将json写入<br>
amazeui-2.4.2/tools/tasks/config/MD5.json<br>

将执行<br>
<code>
sprintf(cmd,"/root/node-v0.12.7-linux-x64/bin/gulp customize --type \"%s\" --path ./config/%s.json",name,name);
</code>
<br>
gulp customize --type \"MD5\" --path ./config/MD5.json<br>
将构造的目录设定为<br>
amazeui-2.4.2/dist/MD5<br>

通过ZIP压缩 amazeui-2.4.2/dist/MD5  To  MD5.ZIP<br>
随后 将 MD5.ZIP  MV TO  网站服务器 <br>
<br>
最终C++服务端Socket将返回On回到PHP 确认成功<br>
PHP跳转URL下载该ZIP压缩包<br>
