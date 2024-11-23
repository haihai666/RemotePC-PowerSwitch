利用 ESP8266 和继电器模块实现远程控制电脑电源。通过网页界面，你可以远程发送开机和强制关机信号，在硬件上开关机

功能：
远程开机：点击按钮即可远程开机。
强制关机：模拟长按电源键 8 秒，强制关机。
简单的 网页界面，由 ESP8266 托管。
Wi-Fi 控制，不需要在电脑上安装任何额外的软件或硬件。
支持任何连接到同一 Wi-Fi 网络的设备。
需求：
一块 ESP8266 开发板（如 NodeMCU）。
一个继电器模块，用于与电脑电源按钮连接。
Arduino IDE，用于将代码上传到 ESP8266。

代码和注释说明：
包括必要的库：注释解释了包括哪些库及其用途（WiFi和web服务器）。
定义常量：解释所使用的wif、wifi密码和继电器模块。
处理请求：每个处理请求的功能（开机和强制关机）都包括注释，以解释激活继电器背后的逻辑以及如何模拟关机动作（8秒保持）。
WiFi设置和连接：提供有关ESP8266如何连接到Wi-Fi并输出设备IP地址的详细信息。
服务器路由和功能：描述打开电脑的路由/开机和强制关机的路由/关机。
循环：一个简单的注释，解释循环用于处理传入的HTTP请求。

This project uses the ESP8266 and a relay module to remotely control your computer's power. Through a web interface, you can send power-on and force-shutdown signals to your computer, allowing you to turn the computer on or off remotely over Wi-Fi.

Features:
Remote Power On: Click a button to power on your computer remotely.
Force Shutdown: Simulate a long press on the power button for 8 seconds to force shutdown.
Simple web interface hosted by the ESP8266.
Wi-Fi Control: No need to install additional software or hardware on your computer.
Compatible with any device connected to the same Wi-Fi network.
Requirements:
One ESP8266 development board (such as NodeMCU).
A relay module to interface with your computer's power button.
Arduino IDE to upload the code to the ESP8266.
