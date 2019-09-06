#########################
Training Style Templates
#########################

Introduction text.


Assignment 1
------------

And some more text.


Formatting
-----------

Some paragraph 

**Some bold text:**

*Some italic text:*


.. .. This is how to write a comment line.

.. ..
   This is a multiline
   Comment. Indentation is important!
   Blocks in rst are closed by a non-indented line

This is a style for numbered instructions:

.. .. An example of a numbered list.

#.  Open a terminal 

#.  Execute some shell scripts

    .. code-block:: bash
 
       pwd
       ls -la
       roscore

#. Just watch how things are running

#. Here is an image:

    .. figure:: ClearBot_software_architecture_gen.png
        :scale: 70 %

        ..

* First bullet
* Second bullet
* Third bullet

Here comes a note
    .. note:: Use note for various remarks which are not directly related to the main content

Here comes a tip
    .. tip:: Press CTRL+C to stop the program.

Here comes a see also box
    .. seealso:: Press CTRL+C to stop the program.

Here comes a warning
    .. warning:: A multi
                 
                 line
                 
                 warning.



Include content
---------------

.. .. Let's include some content from another file.

The following stuff is included from :code:`included.rst`

.. include:: included.rst

