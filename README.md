# Project is in Development and is estimated to be finished before christmas!

# Information about project:


Project is written in c++ and is part of the School activity of Writing program what uses APIs. 
Program uses few Open Source and documented libraries but is mostly self written. you can read more about libraries used in [here](#Depencies)

I got this bad idea after watching some guy building cool Doom like game with exciting looking rendering system. so here we are :). Enjoy

### Rendering

So well many think that I just render all well yes and no this uses some ideas I found youtube and some 1990 game industry's fans may know :). it renders each scene or room player sees as own scene. Well this is atleast the idea is that. (this is written before any part of the rendering part was really written). So idea is to run 

### Initialization

So idea is to use Json files to load map's and spawn points for enemies

### Optimization

so the problem here is that this had to be written in one month and also documented in that time so I had to already multitask... Where I am going with this is that there is not that mutch put mind into optimization... well other than the fact of the game testing was done with literal potato... well atleast by 2010 standards.

### Versetility 

Program was not written that in mind and there for it does not have very high definition of it in it

### Graphics

Well when I started to plan this project I wanted just some kind of surfing idea but then I saw cool 3D game with same kind of idea where there was dynamicly animated eye ball... One of my friends also talked on the same time about some random steam games and that lead to doom kind of game graphic level with amateur graphics creator with too mutch on his plate.


### Use of AI

Good question in my opinion since I have only month it is wise to use some kind of map creation thing to make maps but I do not have that mutch time so as long as it is not used in commercial use it is fine... Well I had to make some kind of map creator and to save time I just made about 5000 copyright infringement... YAY pls dont sue me... anyways... since my main thing is in openGL part and 3D rendering month to do it is little time counting up also to the matter that it needs to be playable. me doing json files by hand oh boy lol.



# Contents:

- [Depencies](#Depencies)
- [Exeption codes](#Exceptions)
- [Links used](#Links)

# Depencies 

Project uses some third party open source documented libraries. Libraries used in this project are:

<details>
<summary>

## 1. [GLFW: OpenGL Library.](https://www.glfw.org/)

</summary>

Funny according to google GLFW is a API itself but well it is only capable of creating windows and perform simple tasks... it won't impress
any one right? well in any case it is used as such in this program. only for creating and handling window and its call backs.

</details>

<details>
<summary>

## 2. [OpenGL (glad).](https://www.opengl.org/)

</summary>

So even tho it is linked to opengl's web page it is convienient to have some sort of loader for methods and functions behid the scenes...
And Well this does excactly it. Btw the real link to headers and other is [here](https://glad.dav1d.de/).

</details>

<details>
<summary>

## 3. [GLM: OpenGL mathemathics library.](https://github.com/g-truc/glm)
</summary>

You know it is such a pain to do a lot of work while you know there is some library what already does it and most likely better... Well her we are.

</details>

<details>
<summary>

## 4. [STB Image](https://github.com/nothings/stb/blob/master/stb_image.h)

</summary>

I know the page mentions something about security well... it was only one what I was familiar with already except SDL2 Image well I would have been needed to change GLFW to it and so on... so for the sake of this we use it like this.

</details>



# Exceptions


<details>
<Summary>

##  - GLFW initialization failure. 0x100F

</summary>

Exception is raised when ever program fails to initialize GLFW API. 

</details>
<details>
<Summary>

## - Window creation failure. 0x101F

</summary>

Exception is raiseed when ever program fails to create window.

</details>
<details>
<Summary>

## - OpenGL initialization failure 0x200F

</summary>

Exception is raised when ever program fails to load OpenGL methods.
</details>

# Links

<details>
<summary>

## Main

</summary>


<blockquote>

<details>
<summary>

### 1. [OpenGL documentation](https://www.opengl.org/)

</summary>

I Know someone would want to see chat gpt code... But you wont instead you see my horrible codee to be impressed
I actually feel sorry for you my boy

</details>
<details>
<summary>

### 2. [GLFW documentation](https://www.glfw.org/documentation)

</summary>

Well here is the documentation of OpenGL Window management API thingy...
it is used for managing windows and key callbacks Yay!

</details>



<details>
<summary>

## 3. [The OpenGL Mathematics (GLM) Library](https://web.engr.oregonstate.edu/~mjb/cs491/Handouts/GLM.1pp.pdf)

</summary>

It was pain to find documentation but here some sort of :)

</details>
</details>

<details>
<summary>

