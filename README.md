# CUSTOMIZED-SMART-METER
A SMART WATER METER USING THE FOLLOWING COMPONENTS.

This code uses interrupts to count the number of pulses from the flow sensor, and then calculates the flow rate and volume based on the time between pulses. If the flow volume exceeds a certain threshold (10.0 liters in this case), the solenoid valve is activated for 1 second and an SMS message is sent.

Note that this is just a sample code and may need to be modified depending on the specific requirements of your project. Also, make sure to replace the phone number in the sendSMS function with the actual phone number you want to send the message to.


Based on the information you provided, it sounds like there may be a few different issues at play.

Firstly, negative values from the YSF201 water flow sensor could be caused by a few different factors. One possibility is that the sensor is not being powered or connected correctly. Make sure that the sensor is receiving power, and that the signal wires are properly connected to the Arduino.

Another possibility is that the sensor is not calibrated correctly. The YSF201 sensor can be affected by factors like temperature and water pressure, so it's important to calibrate it properly for accurate readings. You may need to adjust the calibration constants in your code to account for any variations.

In addition to the negative values, inconsistent results from the sensor could also be due to a lack of filtering or smoothing of the data. Flow sensors can be sensitive to small fluctuations in the water flow, which can cause the readings to jump around. You can try using a moving average or low-pass filter to smooth out the data and remove any high-frequency noise.


Finally, issues with the relay, solenoid valve, or SIM800l module could also be affecting the overall performance of your system. Make sure that these components are working properly and that they are properly interfaced with the Arduino.

It may also be helpful to break your code down into smaller components and test each one individually to isolate any issues. This can help you identify the root cause of the problem and make it easier to troubleshoot.
