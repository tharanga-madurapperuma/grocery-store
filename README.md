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
<br>
<h4>👉 General grocery stores Information</h4>
<p>This option should show the number of grocery stores that were loaded from the file, followed by the number of large grocery stores. Lastly, it should list the average size of large grocery stores only including grocery stores for which the square footage is known. Show the average size with 1 digit after the decimal.</p>

>[!TIP]
>Your choice: 1<br>
>Number of grocery stores: 40<br>
>Number or large grocery stores: 19<br>
>Average size of large grocery stores: 26067.3<br>

<br>
<h4>👉 Neighborhood Charts</h4>
<p>This option should list each neighborhood, and list an L for each large store in the neighborhood, then an S for each small store. For example, Armour Square has one large store and four small stores, so it would have LSSSS. Stores should be listed in order of the number of stores, with the most stores first. If there are two neighborhoods with the same number of stores, list those neighborhoods in alphabetical order.</p>

>[!TIP]
>Your choice: 2<br>
>WEST TOWN -----------> LLLLLLLSSSSSSS<br>
>LOWER WEST SIDE -----> LLLLLSSSSSS<br>
>NEAR WEST SIDE ------> LLLLLSSSS<br>
>ARMOUR SQUARE -------> LSSS<br>
>NEAR SOUTH SIDE -----> LS<br>

<br>
<h4>👉 Find Closest Stores</h4>
<p>This option asks the user for a latitude and longitude, then finds the store that is closest to that point, and the large store that is closest to that point. The distance (with one digit after the decimal) as well as the name and address of the stores should be included in the message. If they are the same store, it should say "That is a large store." rather than repeating the same store's information. 

If a location is a food desert, it should also output "This location is a food desert." A location is not a food desert if it is within half a mile of any store, or within one mile of a large store. It is a food desert if neither of those applies. (Note that since the file we're using in this demo only includes grocery stores fairly close to UIC, it may identify a location away from UIC to be a food desert, even though it's near a grocery store (just not near one that's in this file).</p>

>[!TIP]
>Your choice: 3<br>
>Enter latitude: 41.8745212 <br>
>Enter longitude: -87.6555109<br>
>The closest store is 0.5 miles away.<br>
>  ATHENS GROCERY is at 324 S HALSTED ST<br>
>The closest large store is 0.6 miles away.<br>
>  ARISTA FOODS is at 112 N MAY ST<br>
<p>or</p>
<br>

>[!TIP]
>Your choice: 3<br>
>Enter latitude: 41.8656208<br>
>Enter longitude: -87.6495758<br>
>The closest store is 0.5 miles away.<br>
>  DOMINICK'S #147/1147 is at 1340 S CANAL ST<br>
>That is a large store.<br>
<p>or</p>
<br>

>[!TIP]
>Your choice: 3<br>
>Enter latitude: 41.921707<br>
>Enter longitude: -87.6362152<br>
>The closest store is 1.5 miles away.<br>
>  STANLEY'S is at 1558 N ELSTON AVE<br>
>That is a large store.<br>
>This location is a food desert.<br>

<br>
<h4>👉 Search for Store by Name</h4>
<p>This option gives the user a chance to look for grocery stores by name. The program should allow the user to enter a word or phrase to search for, and output information about any store that contains that phrase in the name. If multiple stores have the search phrase, they should be listed in the order they were in the file. If no stores have that phrase, the program should display "No stores found."</p>

>[!TIP]
>Your choice: 4<br>
>Enter store to search for: Dominick's<br>
>Store: DOMINICK'S FINER FOODS - STORE # 2775<br>
>Address: 2021 W CHICAGO AVE<br>
>Community: WEST TOWN<br>
>Size: Large<br>
>Square Feet: 54963<br>
>
>Store: DOMINICK'S #147/1147<br>
>Address: 1340 S CANAL ST<br>
>Community: NEAR WEST SIDE<br>
>Size: Large<br>
>Square Feet: 68000<br>
>
>Store: DOMINICK'S #1875<br>
>Address: 1 N HALSTED ST<br>
>Community: NEAR WEST SIDE<br>
>Size: Large<br>
>Square Feet: 39000<br>
<br>

>[!TIP]
>Your choice: 4<br>
>Enter store to search for: Whole Foods<br>
>Store: WHOLE FOODS MARKET<br>
>Address: 1101 S CANAL ST<br>
>Community: NEAR WEST SIDE<br>
>Size: Large<br>
>Square Feet: 11310<br>
<br>

>[!TIP]
>Your choice: 4<br>
>Enter store to search for: Toys<br>
>No stores found.<br>
<br>
<br>
<br>
<br>
<br>

>[!CAUTION]
>Creating a List of Neighborhoods
<h4>👉 Creating a List of Neighborhoods</h4>
<p>To create a list of neighborhoods, you can create a vector of strings (to remember the name of the neighborhood). Then go through the list of stores: for each store, check to see if the neighborhood is already in the vector of strings. If it is, you don't need to do anything; if it's not you should add it to the end. Once you've done that with each store, you'll have a list of all the neighborhoods in the file. You can then work with one neighborhood at a time and count the number of large and small stores. For example, if the current neighborhood is Near West Side, go through the entire list of stores and, if you see one from the Near West Side, add it to the counts of the number of stores.</p>
<br>
  
>[!CAUTION]
>Sorting the List of Neighborhoods
<h4>👉 Sorting the List of Neighborhoods</h4>
<p>Since we want to display the neighborhoods in order from the most stores to the least, we'll need to sort the list in some way. You may write your own sort, but you can also use the sort function that is in #include<algorithm>. The sort function can work with a vector, and sorts the objects using the < operator to determine which object goes first. So, if you create a Neighborhood class, you can write a < operator to determine whether one neighborhood should get displayed before another. To use the sort function, you call it with the beginning and end of the list (to tell it to sort the whole thing). If neighborhoods is our vector, we could call:</p>


