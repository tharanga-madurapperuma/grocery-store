# 🚀 Grocery Store using C++
<br>
<br>
<h3>💠 Overview</h3>
<p>For this project, we'll be using data from a project studying food deserts in the city of Chicago (areas without easy access to grocery stores). Your program will allow the user to search for specific grocery stores, find the nearest grocery store to a given location, and analyze the number and size of grocery stores in each neighborhood.</p>
<p>You must use classes in this project. You must use a Store class in this project to keep track of one grocery store. The Store class should keep track of only one grocery store, so the main method or another class should have a vector of Stores to be able to keep track of many of them. 
  
You may also want to use a neighborhood classes to keep track of the number of stores in each neighborhood, or any other classes that you feel would be helpful.</p>
<br>

<h3>💠 Data</h3>
<p>A few sample files are provided for you, and your program should work with any valid file, including files with different neighborhood names. Each grocery store is on a separate line in the file, with the following information, separated by commas:</p>
<ul>
  <li>Name</li>
  <li>Square Feet (the size of the grocery store, listed as 0 if it's unknown)</li>
  <li>Size ("Large" or "Small" depending on whether the store is above 10,000 square feet.) Although this data should match the square feet, we'll need use this string because there are stores where the square footage is not known, but the grocery store is listed as large.</li>
  <li>Address</li>
  <li>Neighborhood</li>
  <li>Latitude</li>
  <li>Longitude - The latitude and longitude give the location of the store</li>
</ul>
<br>
<p><b>For example:</b></p>
<p>ATHENS GROCERY,2600,Small,324 S HALSTED ST,NEAR WEST SIDE,41.87716213,-87.64736429</p>
<br>

<h3>💠 Your Program</h3>
<p>The program should first prompt the user to enter the datafile to use, and then show the user a menu:</p>

>[!TIP]
>Enter filename: near-uic.txt
>
>Select a menu option:
>   1. Display general grocery stores information
>   2. Display neighborhood charts
>   3. Find closest stores
>   4. Search for store by name
>   5. Exit
>Your choice:
<p>The program should exit if the user chooses 5. Otherwise, the program should perform the appropriate task, and then return to the main menu. Each menu item is described below, along with example outputs.</p>
