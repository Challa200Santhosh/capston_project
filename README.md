# ☀️ Modular Solar-Powered Harvest Drying Machine (B.Tech Capstone)

![ESP32](https://img.shields.io/badge/MCU-ESP32-E7352C)
![DHT22](https://img.shields.io/badge/Sensor-DHT22-blue)
![Simulink](https://img.shields.io/badge/Model-MATLAB%2FSimulink-orange)
![IoT](https://img.shields.io/badge/IoT-Wi--Fi%20web%20dashboard-2ea44f)

A solar-powered dryer for fruits, vegetables and herbs that replaces slow, weather-dependent open-air sun drying. Solar-heated air circulates through an insulated drying chamber, and an **ESP32** controller keeps temperature in range by switching a **fan** and a **heater** from **DHT22** temperature and humidity readings. Live readings are served on a Wi-Fi web page.

B.Tech capstone project, GITAM University Bengaluru (Nov 2024 – Mar 2025), built at the Software Defined Vehicle (SDV) Centre.

---

## ⚙️ How the controller works

| Condition | Action |
| :--- | :--- |
| Temperature > 35 °C | Fan **ON** to vent hot, moist air |
| Temperature < 25 °C | Heater **ON** (backup heat for cloudy weather or night) |
| Every client request | Serves a web page with live temperature and humidity |

Pins: DHT22 → GPIO 15 · Fan → GPIO 5 · Heater → GPIO 18

## 📂 Files

| File | Contents |
| :--- | :--- |
| [`Solar_dryer/project_solar.ino`](Solar_dryer/project_solar.ino) | ESP32 firmware: DHT22 sensing, fan and heater control, Wi-Fi web server |
| [`Solar_dryer/SImulink_model_solar_dryer.slx`](Solar_dryer/SImulink_model_solar_dryer.slx) | Simulink model of the dryer |
| [`Solar_dryer/Capston Project final - Report_1.docx`](Solar_dryer/Capston%20Project%20final%20-%20Report_1.docx) | Full project report |
| [`Solar_dryer/project _presentation.pptx`](Solar_dryer/project%20_presentation.pptx) | Project presentation |
| Photos & videos | [hardware](Solar_dryer/Hardware_implementation.jpg) · [physical build](Solar_dryer/phsical_implementation.jpg) · [output](Solar_dryer/output_image.jpg) · [build video](Solar_dryer/physical_implem_video.mp4) · [ESP32 demo](Solar_dryer/ESp32_project%20_vedio.mp4) |

## ▶️ Run the firmware

1. Open `project_solar.ino` in the Arduino IDE with the ESP32 board package and the *DHT sensor library* installed.
2. Set `YOUR_WIFI_SSID` and `YOUR_WIFI_PASSWORD` at the top of the file.
3. Upload to the ESP32, open the Serial Monitor at 115200 baud, and browse to the IP address it prints.

## 👤 Author

**Challa Santhosh** — Model-Based Design & Embedded AI Engineer  
[LinkedIn](https://www.linkedin.com/in/challa-santhosh-36693828a/) · [GitHub](https://github.com/Challa200Santhosh) · sschalla10@gmail.com
