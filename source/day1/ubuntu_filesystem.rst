Exploring the Linux File System
===============================

In this exercise, we will look at how to navigate and move files in the Linux file system using the Ubuntu GUI, and learn some of the basics of Linux file attributes.

Using the File Browser to Navigate
----------------------------------

#. Open the folder browser application we opened in the :doc:`previous exercise <ubuntu_gui>`. You should see a window like the one below. The icons and text above the main window show the current location of the window in the file system. 

   .. figure:: ../_static/pics/ubuntu_file_system.png
      :scale: 70%

#. The icons at the top constitute the "location bar" of the file browser. While the location bar is very useful for navigating in the GUI, it hides the exact location of the window. You can show the location by pressing :kbd:`Ctrl+L`. You should see the location bar turn into something like the image below: 

   .. figure:: ../_static/pics/ubuntu_file_system_location.png
      :scale: 70%

#. The folder browser opens up in the user's home folder by default. This folder is typically :code:`/home/<username>`, which in this training computer is :code:`/home/academy`. This folder is the only one which the user has full access to. This is by design for security's sake.

#. By default, the file browser doesn't show hidden files (files which begin with a . character) or "backup" files (which end with a ~ character). To show these files, click on the "View" menu, and select "Show Hidden Files" (or press :kbd:`Ctrl+H`). This will show all of the hidden files. Uncheck the option to re-hide those files.

#. Two hidden directories are *never* shown: 

      | "." -- a folder, which is a special folder that represents the current folder
      | ".." -- a folder which represents the parent folder of the current folder. These will become important in the :doc:`next exercise <ubuntu_shell>`. 

#. On the left hand side of the window are some quick links to removable devices, other hard drives, bookmarks, etc. Click on the "Computer" shortcut link. This will take you to the "root" of the file system, the / folder. All of the files on the computer are in sub-folders under this folder.

#. Double click on the *opt* folder, then the *ros* folder. This is where all of the ROS software resides. Each version is stored in its own folder; we should see a kinetic folder there. Double-click on that folder. The *setup.bash* file will be used later in this training to configure the terminal for ROS. The programs, data, etc. are in the *bin* and *share* folders. You generally do not need to modify any of these files directly, but it is good to know where they reside.


Making changes
--------------

Next, you will learn to create, change, rename, and remove files and folders.

#. Make a directory :code:`<Home>/linux_intro`. We will be working within this folder.

   #. Inside the file browser, click on the "Home" shortcut in the left sidebar.
   #. Right click in the file browser's main panel and select "New Folder".
   #. Name the folder "linux_intro" and press "Enter".

#. Make a file *test.txt* inside the newly-created *linux_intro* folder.

   #. Double-click on the *linux_intro* folder.  Note how the File Browser header changes to show the current folder.
   #. Right click in the file browser's main panel and select "New Document", then "Empty Document".
   #. Name the file "test.txt" and press "Enter".

#. Copy the file using one of the following methods:

   * Click and hold on the *test.txt* file, hold down on the control key, drag somewhere else on the folder, and release.
   * Click on the file, go to the "Copy" from the "Edit" menu, and then "Paste" from the "Edit" menu.

     .. hint:: To see the Menu, hover your mouse above the bar at the top of the screen

#. Rename the copied file to *copy.txt* using one of the following methods:

   * Right-click on the copied file, select "Rename..." and enter *copy.txt*.
   * Click on the file, press the F2 key, and enter *copy.txt*.

#. Create a folder *new* using one of the following methods:

   * Right-click on an open area of the file browser window, select "New Folder", and naming it *new*
   * Select "New Folder" from the "File" menu, and naming it *new*

#. Move the file *copy.txt* into the *new* folder by dragging the file into the *new* folder.

#. Copy the file *test.txt* by holding down the Control key while dragging the file into the new folder.

#. Navigate into the *new* folder, and delete the *test.txt* folder by clicking on the file, and pressing the delete key.
