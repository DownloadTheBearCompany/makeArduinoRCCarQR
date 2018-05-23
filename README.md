# QR Code tracking, Arduino RC car

# YouTube

[![Video]( https://img.youtube.com/vi/23IQIM-rqoI/maxresdefault.jpg)](http://www.youtube.com/watch?v=23IQIM-rqoI)

# Credits

| Type   | Descriptions                                                                                            |
| ------ | -------------------------------------------------------------------------------------                   |
| Music  | RaYnold JR Fairytales By Raynold JR                                                                     |
| Music  | Otis McDonald Not For Nothing Music written, performed, produced, mixed, and mastered by Otis McDonald. |

# Links

| Name                     | Link                                                                           |
| ---                      | ---                                                                            |
| EAGLE-3 RC car           | [Amazon][RCCar]                                                                |
| Spectrum Analyzer shield | [Ebay][shield]                                                                 |
| Twitter                  | [@MichaelTiBear](https://twitter.com/MichaelTiBear)                            |
| Facebook                 | [Follow me on Facebook!](https://www.facebook.com/michael.ti.bear)             |
| Instagram                | [Check it out!](https://www.instagram.com/michaeltibear/)                      |
| Website                  | [Everything can be found at downloadthebear.com](https://downloadthebear.com/) |

# What is it
Recently, I got a [EAGLE-3 RC car][RCCar]. I admit it was quite fun. However, the
controller that came with the remote control car is not very responsive. I
decided to convert it into a standard hobby RC car. It lived up to my expectation.
Which is very nice.

While I was modifying the EAGLE-3. My Arduino arrived in my mailbox. Could
I double the fun with an Arduino?! The answer is most definitely, yes! I replaced
the remote receiver with an Arduino/Spectrum Analyzer shield and the controller
with iPhone. And, we are done! Maybe not so much.

# Talk about the different designs

Ok, Let's talk about the iPhone. There's almost no doubt that it's a very
powerful mobile phone. Is it the most powerful one?! I will have to let you
decide. However, the iPhone is the most ubiquitous and uniform device of all the
mobile phones. In a scene it's very similar to the Arduino Uno, but on a much
larger scale.

In order to use them both in our project, we need to talk about communication.
The primary communication methods for the iPhone with the outside world.
- Wifi
- Bluetooth
- NFC and many more.
- The one method that caught my attention is the headphone jack, or the lack of
it in the newer models. However, there are adopters available to gain headphone
jack.
    - The audio protocol has very little overhead and low latency. This perfect
    for many projects that requires low latency communication.
    - It requires almost no setup, just remember to install the RealSmartz App.

Just like the real world, a communication channel needs a listener. Let's talk
about the Arduino.
- USB connection
- GPIO pins

Neither of the methods are very mobile phone friendly. However, there are shields
available to extend the functionality.
- WIFI shields
- Bluetooth shields
- Spectrum Analyzer Shield. It's can process 7 frequencies of an audio input source.

And I will be using the headphone jack to communicate the intent to the Arduino.

# Flush out the idea

To summarize, here's the plan. We are going to launch the RealSmartz App.
The App will make the iPhone act as a microcontroller has a QR Code detecting
camera. We can modify the threshold value to the desire amount. The left
bar signifies the left turn and respective for the right. The Arduino will
receive a turn signal when the QR Code intercept the bar. Change the forward area
threshold value and reverse area threshold to the desire amount.

Next, we will then plug in the iPhone to the Spectrum Analyzer shield. Connect
the signal wires of the RC car to the Arduino. In this case, I'm using the 3 and
5 pwm pin to control the servo and esc. Load up the Arduino program. Print out
the QR Code from the App. Presto! We have the basic setup and ready to go.

# DONE

And we are Done. There could be many improvements to this project. Let me know
in the comments down below. Follow me on the social media channels. If you
have any questions about the code, feel free to file an issue on the github
project.


As always, this is Michael Ti. See you next week with Michael!

[RCCar]: https://www.amazon.com/gp/product/B01KA3EX72/ref=oh_aui_detailpage_o06_s00?ie=UTF8&psc=1
[MSGEQ7]: https://www.sparkfun.com/datasheets/Components/General/MSGEQ7.pdf
[shield]: https://www.ebay.ca/itm/Arduino-Uno-Compatible-Dual-MSGEQ7-Spectrum-Analyzer-Breakout-Board-Shield/322061389365?hash=item4afc5ace35:g:BUsAAOSwal5YDtzw

