#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#define RELAY_PIN 5  // 定义继电器控制引脚 (GPIO5，对应 D1)

// Wi-Fi 配置
const char* ssid = "你的WiFi名称";
const char* password = "你的WiFi密码";

// 创建 Web 服务器
ESP8266WebServer server(80);

// 生成 HTML 网页
String generateHTML() {
  String html = "<!DOCTYPE html><html><head>";
  html += "<meta charset=\"UTF-8\">";  // 明确指定 UTF-8 编码
  html += "<title>电脑控制</title></head>";
  html += "<body><h1>电脑控制页面</h1>";
  html += "<form action=\"/power\" method=\"POST\">";
  html += "<button type=\"submit\">开机</button>";
  html += "</form>";
  html += "<form action=\"/shutdown\" method=\"POST\">";
  html += "<button type=\"submit\">强制关机</button>";
  html += "</form>";
  html += "</body></html>";
  return html;
}

// 处理主页请求
void handleRoot() {
  server.send(200, "text/html; charset=UTF-8", generateHTML());
}

// 处理开机请求
void handlePower() {
  digitalWrite(RELAY_PIN, HIGH);  // 启动继电器
  delay(1000);                    // 模拟按下开机键 1 秒
  digitalWrite(RELAY_PIN, LOW);   // 释放继电器
  server.send(200, "text/html; charset=UTF-8", "<!DOCTYPE html><html><head><meta charset=\"UTF-8\"></head><body><p>开机信号已发送！</p><a href=\"/\">返回</a></body></html>");
}

// 处理强制关机请求
void handleShutdown() {
  digitalWrite(RELAY_PIN, HIGH);  // 启动继电器
  delay(8000);                    // 模拟按下电源键 8 秒
  digitalWrite(RELAY_PIN, LOW);   // 释放继电器
  server.send(200, "text/html; charset=UTF-8", "<!DOCTYPE html><html><head><meta charset=\"UTF-8\"></head><body><p>强制关机信号已发送！</p><a href=\"/\">返回</a></body></html>");
}

void setup() {
  // 初始化串口
  Serial.begin(115200);

  // 配置继电器引脚
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);

  // 连接 Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("正在连接 WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nWiFi 已连接！");
  Serial.print("设备 IP 地址: ");
  Serial.println(WiFi.localIP());

  // 设置服务器路由
  server.on("/", handleRoot);
  server.on("/power", handlePower);
  server.on("/shutdown", handleShutdown);

  // 启动服务器
  server.begin();
  Serial.println("Web 服务器已启动！");
}

void loop() {
  server.handleClient();  // 处理网页请求
}
