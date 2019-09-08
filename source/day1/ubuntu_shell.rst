The Linux Terminal
==================

In this exercise, we will familiarize ourselves with the Linux terminal.

Starting the Terminal
---------------------

#. To open the terminal, click on the terminal icon: 

     .. figure:: ../_static/pics/ubuntu_terminal_icon.png
        :scale: 70%

#. Create a second terminal window, either by:

   * Right-clicking on the terminal and selecting the "Open Terminal" or
   * Selecting "Open Terminal" from the "File" menu

#. Create a second terminal within the same window by pressing :kbd:`Ctrl+Shift+T` while the terminal window is selected.

#. Close the 2nd terminal tab, either by:

   * clicking the small 'x' in the terminal tab (not the main terminal window)
   * typing :code:`exit` and hitting enter.

#. The window will have a single line, which looks like this:

   .. code-block:: bash

      academy@laptop-0:~$

#. This is called the prompt, where you enter commands. The prompt, by default, provides three pieces of information:

   #. :code:`academy` is the login name of the user you are running as.
   #. :code:`laptop-0` is the host name of the computer.
   #. :code:`~` is the directory in which the terminal is currently in. (More on this later).

#. Close the terminal window by typing :code:`exit` or clicking on the red 'x' in the window's titlebar.

Navigating Directories and Listing Files
----------------------------------------

Prepare your environment
************************

#. Open the file browser, by clicking on the following icon:

   .. figure:: ../_static/pics/ubuntu_file_browser_icon.png
      :scale: 70%

#. Navigate to the home directory.

#. Double-click on the :code:`linux_intro` folder we created in the previous step.

   * We'll use this to illustrate various file operations in the terminal.

#. Right click in the main file-browser window and select "Open in Terminal" to create a terminal window at that location.
#. In the terminal window, type the following command to copy some sample files that we can study later:

   .. code-block:: bash

      cp -a ~/ros_training/resources/linux_intro/. .

ls Command
**********
#. Enter :code:`ls` into the terminal. 

   * You should see :code:`test.txt`, and :code:`new` listed. (If you don't see 'new', go back and complete the :doc:`previous exercise <ubuntu_gui>`.
   * Directories, like :code:`new`, are colored in blue.
   * The file :code:`sample_job` is in green; this indicates it has its "execute" bit set, which means it can be executed as a command.

#. Type :code:`ls *.txt`. This lists all the files ending with ".txt". Only the file :code:`test.txt` will be displayed.

#. Enter :code:`ls -l` into the terminal.

   * Adding the :code:`-l` option shows one entry per line, with additional information about each entry in the directory.
   * The first 10 characters indicate the file type and permissions
   * The first character is :code:`d` if the entry is a directory.
   * The next 9 characters are the permissions bits for the file
   * The third and fourth fields are the owning user and group, respectively.
   * The second-to-last field is the time the file was last modified.
   * If the file is a symbolic link, the link's target file is listed after the link's file name.

#. Enter :code:`ls -a` in the terminal.

   * You will now see one additional file, which is hidden (i.e. its name begins with a dot).
     
#. Enter :code:`ls -a -l` (or :code:`ls -al`) in the command.

   * You'll now see that the file :code:`hidden_link.txt` points to :code:`.hidden_text_file.txt`.

   .. tip:: If you check the contents of :code:`.bashrc` in your home folder, you will find that several aliases (:code:`l`, :code:`ll`, and :code:`la`) have been defined. These are real time savers when using :code:`ls` with arguments often.

pwd and cd Commands
***********************************

 #. Enter :code:`pwd` into the terminal.

    * This will show you the full path of the directory you are working in.

 #. Enter :code:`cd new` into the terminal.

    * The prompt should change to :code:`academy@laptop-0:~/linux_intro/new$`.
    * Typing :code:`pwd` will show you now in the directory :code:`/home/academy/linux_intro/new`.

 #. Enter :code:`cd ..` into the terminal.

    * In the :doc:`previous exercise <ubuntu_gui>`, we noted that :code:`..` is the parent folder. 
    * The prompt should therefore indicate that the current working directory is :code:`/home/academy/linux_intro`.
      
 #. Enter :code:`cd /bin`, followed by :code:`ls`.

    * | This folder contains a list of the most basic Linux commands.
      | Note that the programs :code:`pwd` and :code:`ls` are both in this folder.

 #. Enter :code:`cd ~/linux_intro` to return to our working directory.

    * Linux uses the :code:`~` character as a shorthand representation for your home directory.
    * It's a convenient way to reference files and paths in command-line commands.
    * You'll be typing it a lot in this class... remember it!

    .. hint:: If you want a full list of options available for any of the commands given in this section, type :code:`man <command>` (where `<command>` is the command you want information on) in the command line. This will provide you with built-in documentation for the command. Use the arrow and page up/down keys to scroll, and :code:`q` to exit.


Altering Files
--------------

mv Command
**********
The :code:`mv` command can be used to move and rename files.

 #. Type :code:`mv test.txt test2.txt`, followed by :code:`ls`.

    * You will notice that the file has been renamed to :code:`test2.txt`.

 #. Type :code:`mv test2.txt new`, then :code:`ls`.

    * The file will no longer be present in the folder. 

 #. Type :code:`cd new`, then :code:`ls`.
    
    * You will see that :code:`test2.txt` has been moved into the :code:`new` folder.

 #. Type :code:`mv test2.txt ../test.txt`, then :code:`ls`.

    * :code:`test2.txt` will no longer be there.

 #. Type :code:`cd ..`, then :code:`ls`.

    This shows how :code:`mv` can move and rename files in one step. The file :code:`test.txt` is present again in our working directory.

cp Command
**********
 #. Type :code:`cp test.txt new/test2.txt`, then :code:`ls new`.

    * You will see :code:`test2.txt` is now in the :code:`new` folder.

 #. Type :code:`cp test.txt "test copy.txt"`, then :code:`ls -l`.

    * You will see that :code:`test.txt` has been copied to :code:`test copy.txt`.

    .. note:: The quotation marks are necessary when spaces or other special characters are included in the file name.

rm Command
**********

 #. Type :code:`rm "test copy.txt"`, then :code:`ls -l`.

    * You will notice that :code:`test copy.txt` is no longer there.


mkdir Command
*************
 #. Type :code:`mkdir new2`, then :code:`ls`.

    * You will see there is a new folder :code:`new2`.

    .. tip:: You can use the  :code:`-i` flag with :code:`cp`, :code:`mv`, and :code:`rm` commands to prompt you when a file will be overwritten or removed.


Job management
--------------

Stopping Jobs
*************
 #. Type :code:`./sample_job`.

    * The program will start running.

 #. Press :kbd:`Control+C`.

    * The program should exit.

 #. Type :code:`./sample_job sigterm`.

    * The program will start running.

 #. Press :kbd:`Control+C`.

    * This time the program will not die.

Stopping "Out of Control" Jobs
******************************
 #. Open a new terminal window.
 #. Type :code:`ps ax`.
 #. Scroll up until you find :code:`python ./sample_job sigterm`.

    * This is the job that is running in the first window.
    * The first field in the table is the ID of the process (use :code:`man ps` to learn more about the other fields).

 #. Type :code:`ps ax | grep sample`.

    * You will notice that only a few lines are returned.
    * This is useful if you want to find a particular process
    .. note:: This is an advanced technique called "piping", where the output of one program is passed into the input of the next. This is beyond the scope of this class, but is useful to learn if you intend to use the terminal extensively.

 #. Type :code:`kill <id>`, where :code:`<id>` is the job number you found with the :code:`ps ax`.

 #. In the first window, type :code:`./sample_job sigterm sigkill`.

    * The program will start running.

 #. In the second window, type :code:`ps ax | grep sample` to get the id of the process.

 #. Type :code:`kill <id>`.

    * This time, the process will not die.

 #. Type :code:`kill -SIGKILL <id>`.

    * This time the process will exit.

Showing Process and Memory usage
********************************
 #. In a terminal, type :code:`top`.

    * A table will be shown, updated once per second, showing all of the processes on the system, as well as the overall CPU and memory usage.

 #. Press the :kbd:`Shift+P` key.

    * This will sort processes by CPU utilization and shows which processes are using too much CPU time.

 #. Press the Shift+M key.

    * This will sort processes by memory utilization and shows which processes are using too much memory.
    
 #. Press :kbd:`q` or :kbd:`Ctrl+C` to exit the program.

Editing Text (and Other GUI Commands)
*************************************
 #. Type :code:`gedit test.txt`.

    * You will notice that a new text editor window will open, and :code:`test.txt` will be loaded.
    * The terminal will not come back with a prompt until the window is closed.

 #. There are two ways around this limitation.  Try both...

 #. **Starting the program and immediately returning a prompt:**

    #. Type code:`gedit test.txt &`.

       * The :code:`&` character tells the terminal to run this command in "the background", meaning the prompt will return immediately.

    #. Close the window, then type :code:`ls`.

       * In addition to showing the files, the terminal will notify you that :code:`gedit` has finished.

 #. **Moving an already running program into the background:**

    #. Type :code:`gedit test.txt`.

       * The window should open, and the terminal should not have a prompt waiting.

    #. In the terminal window, press :kbd:`Ctrl+Z`. 

       * The terminal will indicate that :code:`gedit` has stopped, and a prompt will appear.

    #. Try to use the :code:`gedit` window.

       * Because it is paused, the window will not run.

    #. Type :code:`bg` in the terminal.

       * The :code:`gedit` window can now run.

    #. Close the :code:`gedit` window, and type :code:`ls` in the terminal window.

       * As before, the terminal window will indicate that :code:`gedit` is finished.

Running Commands as Root
************************
 #. In a terminal, type :code:`ls -a /root`.

    * The terminal will indicate that you cannot read the folder :code:`/root`.
    * Many times you will need to run a command that cannot be done as an ordinary user, and must be done as the "super user"

 #. To run the previous command as root, add :code:`sudo` to the beginning of the command.

    * In this instance, type :code:`sudo ls -a /root` instead.
    * The terminal will request your password (in this case, :code:`academy`) in order to proceed.
    * Once you enter the password, you should see the contents of the :code:`/root` directory.

.. warning:: :code:`sudo` is a powerful tool which doesn't provide any sanity checks on what you ask it to do, so be **VERY** careful in using it.
