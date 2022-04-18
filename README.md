
This repo is based off the simple C++ XML Parser tutorial found here: 
www.codeproject.com/Articles/111243/Simple-Cplusplus-XML-Parser [3]

The project was originally built in Visual Studio 2008, and I have adapted it to build in Visual Studio 2019. 

Below is the only error I experienced during building, and how I solved it. <br>

###  [Solved] Error MSB8041 MFC libraries are required for this project. Install them from the Visual Studio installer (Individual Components tab) for any toolsets and architectures being used. test C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\MSBuild\Microsoft\VC\v160\Microsoft.CppBuild.targets 479


First off, what is the MFC library? <br>
The Microsoft Foundation Class (MFC) Library provides an object-oriented wrapper over much of the Win32 and COM APIs. Although it can be used to create very simple desktop applications, it is most useful when you need to develop more complex user interfaces with multiple controls. You can use MFC to create applications with Office-style user interfaces.
### Installation
Support for MFC and its multibyte character set (MBCS) libraries requires an additional step during Visual Studio installation in Visual Studio 2013 and later. [2]
Visual Studio 2013: By default, the MFC libraries installed in Visual Studio 2013 only support Unicode development. You need the MBCS DLLs in order to build an MFC project in Visual Studio 2013 that has the Character Set property set to Use Multi-Byte Character Set or Not Set. Download the DLL at Multibyte MFC Library for Visual Studio 2013. [2]
Visual Studio 2015: Both Unicode and MBCS MFC DLLs are included in the Visual C++ setup components, but support for MFC is not installed by default. Visual C++ and MFC are optional install configurations in Visual Studio setup. To make sure that MFC is installed, choose Custom in setup, and under Programming Languages, make sure that Visual C++ and Microsoft Foundation Classes for C++ are selected. If you have already installed Visual Studio, you will be prompted to install Visual C++ and/or MFC when you attempt to create an MFC project. [2]
Visual Studio 2017 and later: The Unicode and MBCS MFC DLLs are installed with the Desktop development with C++ workload when you select MFC and ATL support from the Optional Components pane in the Visual Studio Installer program. If your installation does not include these components, navigate to the File | New Projects dialog and click the Open Visual Studio Installer link. For more information, see Install Visual Studio. [2]


Go to Apps and Features and Find Visual Studio

![image](https://user-images.githubusercontent.com/1289702/163818410-2b527411-7af6-477d-92e0-e56079dcf659.png)


Under Language Packs->Installation Details select “C++ MFC for latest v142 build tools”
![image](https://user-images.githubusercontent.com/1289702/163818428-9d55ca12-1bd3-4ada-99b8-0bfa755ec74b.png)

You can also go through "Visual Studio Installer" and then choose to Modify Visual Studio Community 2019 if you like. There are two ways to get the to Component Installation page basically. 
![image](https://user-images.githubusercontent.com/1289702/163818551-558261ec-a0b2-426c-9b7a-0466d22241d7.png)


Make sure you grab this one under "Individual Components". Click the “Modify” button after selecting the MFC Build Tools for x86 and x64 to get started installing it
![image](https://user-images.githubusercontent.com/1289702/163818612-da069705-cf88-405d-8058-f862303dfb5b.png)

Some progress bars will show you how far along it is
![image](https://user-images.githubusercontent.com/1289702/163818675-bdfab559-09dd-460d-ae39-02568c73ac85.png)

Restart Visual Studio and build again.


References
[1] MFC Desktop Applications. https://docs.microsoft.com/en-us/cpp/mfc/mfc-desktop-applications?view=msvc-170 <br>
[2] MFC MBCS DLL Add-on. https://docs.microsoft.com/en-us/cpp/mfc/mfc-mbcs-dll-add-on?view=msvc-170 <br>
[3] Simple C++ XML Parser Tutorial. www.codeproject.com/Articles/111243/Simple-Cplusplus-XML-Parser <br>
