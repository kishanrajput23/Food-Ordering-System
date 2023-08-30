# Food Ordering System

## How To Setup?

### Step 1:

- First of all download this project in your local system and extract the files. Below are details how you can do that:

1. Click on this green color `Code` Button.

<img width="331" alt="image" src="https://user-images.githubusercontent.com/70385488/223937703-c20e271d-badb-4943-9db8-9ab3adde6ec5.png">

2. In dropdown menu please select `Download ZIP` option.

<img width="398" alt="image" src="https://github.com/kishanrajput23/Food-Ordering-System/assets/70385488/40fba74b-0141-479d-8447-68d9fbca7c91">

3. After downloading `ZIP File` please unzip it.

### Step 2:

- Now please open `FOS` folder in your favourite code editor like `VS Code` or you can open in any other editor.

- After that your code editor should look like below :

<img width="1440" alt="image" src="https://github.com/kishanrajput23/Food-Ordering-System/assets/70385488/c0c6d487-baf8-44ac-9112-396d931a3568">

- I hope you have followed all above steps carefully. Now you have to change certain things before running this project.

### Step 3:

- Firstly open `main.cpp` file and it should look like this.

<img width="1440" alt="image" src="https://github.com/kishanrajput23/Food-Ordering-System/assets/70385488/5408b752-84ed-4419-b67c-aeab40976825">

- Now you have to make changes in line number 2, and 3.
- In line numnber 2 copy the path of `admin.h` file and paste that path in between double quotes `""`. Please make sure that you should not give any other extra spaces in between double quotes.
- For copying path of `admin.h` file, just right click on `admin.h` file which is located in `include` folder and paste it in line number 2.

<img width="538" alt="image" src="https://github.com/kishanrajput23/Food-Ordering-System/assets/70385488/d65c837d-fed7-4cb5-ac9f-1f52b62e5a6d">

- Now in line numnber 3 copy the path of `customer.h` file and paste that path in between double quotes `""`. Please make sure that you should not give any other extra spaces in between double quotes.
- For copying path of `customer.h` file, just right click on `customer.h` file which is also located in `include` folder and paste it in line number 3.

<img width="518" alt="image" src="https://github.com/kishanrajput23/Food-Ordering-System/assets/70385488/4b5cfc59-08a2-457a-b390-5e3f24d92a84">

### Step 4:

- Open `customer.h` file which is located in `include` folder.
- Now you have to make changes in line number 3.
- I hope you have understood that how you can copy the path of any file. If not please refer above images for better understanding.
- Now copy the path of `admin.h` file which is also located in `include` folder and paste it in line numbers 3.

### Step 5:

- Open `admin.cpp` file which is located in `src` folder.
- Now you have to make changes in line number 192, 248, 249, 332, 333, 382, 383, 420, 421, 465.
- So, copy the path of `food_items.csv` file which is located in `data` folder and paste it in line number 192, 248, 332, 382, 420, 465.
- Now in line number 249 and 383 what you need to do is :
```
copy the path of food_items.csv and paste that path.

for example : /Users/KI20449224/Downloads/FOS/data/food_items.csv

now what you need to do is just remove food_items.csv from above path and write temp.csv

after making changes your path will look like this : /Users/KI20449224/Downloads/FOS/data/temp.csv
```
- Now in line number 333 and 421 what you need to do is :
```
the line of code look like this : rename("/Users/KI20449224/Downloads/FOS/data/temp.csv", "/Users/KI20449224/Downloads/FOS/data/food_items.csv");

what you ave to do is in first "" you have to give path which you gave in line number 249 or 383 and after that in second "" you have to give path of food_items.csv file. 
```
- Finally you have made the all changes in `admin.cpp` file.

### Step 6:

- Open `customer.cpp` file which is located in `src` folder.
- Now you have to make changes in line number 97, 118, 142, 266, 
- So, copy the path of `customer_registration.csv` file which is located in `data` folder and paste it in line number 97, 118, and 142.
- Now copy the path of `food_items.csv` file and paste that in line number 266.
- Finally you have made the all changes in `customer.cpp` file. Now Let's discuss how you gonna run this project successfully.


## How To Run?

- So, if you're using `Mac` then it's very simple to run this project. Firstly open `Terminal` and type `cmd + shift + b` then press `Enter`. After that in `Terminal` type `./make` and hit `Enter`.
- Now if you get any error while building make file then follow below steps:
1. Type  `cmd + shift + p` then click `edit json properties`.
2. In `.vscode` folder create a file named as `tasks.json` only if it is not presnt in that folder like below:

<img width="219" alt="image" src="https://github.com/kishanrajput23/Food-Ordering-System/assets/70385488/d11823f1-9601-4393-b4e4-82a2e9677b33">

3. Open `tasks.json` and paste below code or match the code:
```
{
	"version": "2.0.0",
	"tasks": [
	  {
		"label": "Build",
		"type": "shell",
		"command": "g++",
		"args": [
		  "-std=c++0x",
		  "-o",
		  "make",
		  "main.cpp",
		  "src/admin.cpp",
          "src/customer.cpp",
		  "-arch",
		  "arm64"
		],
		"group": {
		  "kind": "build",
		  "isDefault": true
		}
	  },
	  {
		"label": "Run",
		"type": "shell",
		"command": "${fileDirname}/${fileBasenameNoExtension}"
	  }
	]
  }
```
4. After following above steps your error will be gone.

- Now after running `./make` command the system will give you 3 options and you can perform operations as per your choice:
  
<img width="609" alt="image" src="https://github.com/kishanrajput23/Food-Ordering-System/assets/70385488/e1542079-eaa2-467e-bec8-3405fac12b89">

**Note:** For admin credentials type `admin` as `username` and `12345` as `password`. For customer credentials you can check `customer_registration.csv` file or simply you can register with new `email id` and `password`.

## Still Have Confusion?
- So, after following all above given instructions, still you are facing some difficulties/issues then feel free to reach out to me or just open an issue in this repository and I'll definately get back to you.

## Connect With Me [👤](https://linktr.ee/kishan_rajput23)👈
