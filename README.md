[English](https://github.com/seasea-666/RemotePC-PowerSwitch/blob/main/README-en-us.md)
# RemotePC-PowerSwitch

RemotePC-PowerSwitch 是一个基于 **ESP8266** 和 **继电器模块** 的远程电脑电源控制系统。通过一个简单的网页界面，你可以轻松实现远程开机或强制关机操作，无需安装额外的软件或硬件。

## 功能特点

- **远程开机**：通过网页按钮远程开机。
- **强制关机**：模拟长按电源按钮 8 秒，强制关闭电脑。
- **Wi-Fi 控制**：无需额外的软件，只需确保设备处于同一局域网。
- **网页界面**：简单直观，支持手机、电脑等多种设备。
- **来电自启**：防止停电后动态公网ip变动无法远程访问的情况。

---

## 硬件需求

1. **ESP8266 开发板**  
   - 推荐使用 NodeMCU 或类似的开发板。
   ![esp8622](https://github.com/user-attachments/assets/fd63ad78-fb9a-44b4-b057-d744a0c9a279)

2. **继电器模块**  
   - 用于连接电脑的电源按钮。
![继电器模块](https://github.com/user-attachments/assets/698747f6-98be-438e-9361-abb92bf2468d)
3. **连接线若干**  
   - 用于将 ESP8266 与继电器模块连接起来。

---

## 软件需求

1. **Arduino IDE**  
   - 用于编写和上传代码到 ESP8266。

2. **必要的库**  
   - `ESP8266WiFi.h`：管理 Wi-Fi 连接。
   - `ESP8266WebServer.h`：创建简单的网页服务器。

---

## 接线说明

  ESP8622 --------------- 继电器模块
  
  GPIO5  ------------------>   IN
  
  GND    ------------------>   GND
  
  3.3V/5V ----------------->   VCC
 
继电器模块 --------------- 电源开关

COM ------------------> 电源开关针脚 1

NO  ------------------> 电源开关针脚 2
                               

注意：大部分继电器支持 5V 供电，如果使用 ESP8266 的 3.3V 输出供电，请确认继电器支持 3.3V 启动。

---

## 使用方法

### 1. 配置代码
在代码中填写以下信息：
- Wi-Fi 名称（`SSID`）
- Wi-Fi 密码（`password`）
- 用户名
- 密码
- 继电器控制引脚编号（默认为 GPIO5）(D1)

### 2. 上传代码
使用 Arduino IDE 将代码上传到 ESP8266。

### 3. 获取 IP 地址
上传完成后，打开 Arduino IDE 的串口监视器，查看 ESP8266 的 IP 地址。例如：`192.168.0.2`

### 4. 访问网页
在浏览器中输入 IP 地址（如 `http://192.168.0.2`）。网页包含两个按钮：
- **开机**：点击开机。
- **强制关机**：点击后模拟长按电源键 8 秒，强制关机。

---

## 注意事项

1. **继电器选型**  
   - 确保继电器的工作电压和电流满足 ESP8266 和电脑主板的需求。

2. **供电要求**  
   - 使用稳定的电源为 ESP8266 和继电器模块供电。

3. **网络环境**  
   - 确保控制设备和 ESP8266 处于同一 Wi-Fi 网络中。

4. **安全性**  
   - 由于网页界面通过局域网访问，请避免使用不安全的公共 Wi-Fi 网络。

---

## 示例截图

![示例界面](https://github.com/user-attachments/assets/92aa72c8-5d27-47e5-bafe-b7fc8cebc421)


---

## License

此项目使用 [MIT License](LICENSE)。您可以自由修改和分发代码，但需保留原作者信息。

---

## 贡献

欢迎提交 Issue 或 Pull Request 以改进此项目。如有问题，请通过 GitHub 联系我们。

---

## 声明

此项目仅供个人学习和娱乐用途，使用时请确保符合相关法律法规。
