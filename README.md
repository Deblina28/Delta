# Delta
An automated obstacle avoiding lawn mowing rover


## Inspiration 
One of our teammate's father is very fond of gardening, and this helped us understand the problems faced by people with green thumb better. Other than that, the hackathon's theme also contributed equally to the inspiration factor of the project.

## What it does 
Delta is a 4WD obstacle avoiding rover that is installed with a blade at the bottom, which trims/cuts the grass and weeds growing on the land. Delta will improve your gardening experience by not having to spend any energy and time in manually trimming the grass or weeding out your garden or lawn. Delta will be not crash into any tree or plant or other objects in your garden or yard because of the smart obstacle-avoiding circuitry it works on. The automated process of lawn mowing will bring you efficient results with almost zero manual work or monitoring.

#How we built it 
Delta has an onboard infrared reflectance sensor that is used to detect any kind of obstacle in front of it. Basically, this IR proximity sensor is built using an Infrared LED that emits IR light, which is invisible to our eye. And a photodiode that is capable of measuring the intensity of IR light falling on it. Now, whenever an obstacle comes in front of the IR LED, the light emitted from the LED gets reflected back and hits the photodiode. The current from the photodiode is now measured as a voltage by the ADC of the Arduino via a 10k pullup resistor. Delta has four 300RPM motors in a 4WD configuration. It has two 3.7v LiOn batteries, which spits 7.4v when combined. The heart of Delta is the Arduino microcontroller that reads the signal from the sensors and drives the motors via the L293d motor driver. And for the cutting purpose, a blade is mounted on a motor, which is placed at the bottom of the chassis. With some Arduino Coding and calibrating, we finally got our Delta running on the field.

## Challenges we ran into 
During the testing period, while building the breadboard circuitry, due to the faulty ground connection of the Arduino, we had some trouble getting the readings from the photodiode. While building the hardware projects, we realized the problem might lie right in front of you but, you will still think about what can possibly go wrong. Connecting the motor underneath the chassis was troublesome, and mounting the blade on it too.

## Accomplishments that we're proud of
Making such a cheap and simple obstacle detector was a great feeling. Able to mount the motor underneath the chassis with the blade without hard components. And finally, watching Delta work like a charm by avoiding the obstacles and making its new path was a yay moment and real accomplishment.

## What we learned
We learned about IR LEDs and got to know about them in a better way. We are even surrounded by IR emissions that we don't know about. From flame to heating objects, they emit IR radiations. Obviously, they are not harmful to us. Even our body emits some infrared too. Learned about photodiode, how it converts optical energy to electrical energy. Learned about a trans-impedance amplifier that can convert current into voltage with an amplification factor. Even though we didn't use it here, at least we still got to learn about it. 

## What's next for Delta
Converting this model to an actual automated Lawn Mower that will be capable of cutting the grass and collect it inside a sack simultaneously. Attaching more IR Sensors so that they will detect obstacles with a higher degree of accuracy. Maybe with some omni-wheels, we can give it a three degree of freedom.
