<details>
<summary>

# Project Summary:

</summary>

Project is written in C and is part of the School activity of Writing program what uses APIs. 
Program uses few Open Source and documented libraries but is mostly self written. you can read more about libraries used in [here](#Depencies)

</details>

# Contents:

- [Depencies](#Depencies)
- [Exeption codes](#Exceptions)
- [Links used](#Links)

#Depencies 

Project uses some third party open source documented libraries. Libraries used in this project are:

<details>
<summary>

## [GLFW: OpenGL Library](https://www.glfw.org/)

</summary>

Funny according to google GLFW is a API itself but well it is only capable of creating windows and perform simple tasks... it won't impress
any one right? well in any case it is used as such in this program. only for creating and handling window and its call backs.

</details>

<details>
<summary>
## [OpenGL (glad)](https://www.opengl.org/)
</summary>

So even tho it is linked to opengl's web page it is convienient to have some sort of loader for methods and functions behid the scenes...
And Well this does excactly it. Btw the real link to headers and other is [here](https://glad.dav1d.de/).

</details>




# Exceptions


<details>
<Summary>

##  - GLFW_INITIALIZATION_SELF_FAILURE -2735 

</summary>

Exception is raised when ever program fails to initialize GLFW API. 

</details>
<details>
<Summary>

## - GLFW_INITIALIZATION_WINDOW_FAILURE -2751

</summary>

Exception is raiseed when ever program fails to create window.

</details>
<details>
<Summary>

## - OPENGL_INITIALIZATION_SELF_FAILURE -2991

</summary>

Exception is raised when ever program fails to load OpenGL methods.

</details>


# Links

<details>
<summary>

## Main.C

<details>
<summary>

### 1. [Information about main method in C](https://www.ibm.com/docs/en/i/7.4?topic=functions-main-function)

</summary>

Kind of basic stuff but... I want to ensure all data is described cleeanly as possible.
you know...

</details>

<blockquote>

<details>
<summary>

### 2. [ANSII Color codes](https://gist.github.com/RabaDabaDoba/145049536f815903c79944599c6f952a)

</summary>

for console so that it is easier to recognize exceptions warnings and logs from eatch other.
kinda helping factor when debuggng you know.

</details>

<blockquote>

<details>
<summary>

### 3. [OpenGL documentation](https://www.opengl.org/)

</summary>

I Know someone would want to see chat gpt code... But you wont instead you see my horrible codee to be impressed
I actually feel sorry for you my boy

</details>
<details>
<summary>

### 4. [GLFW documentation](https://www.glfw.org/documentation)

</summary>

Well here is the documentation of OpenGL Window management API thingy...
it is used for managing windows and key callbacks Yay!

</details>

<blockquote>

<details>
<summary>



</summary>



</details>
</details>