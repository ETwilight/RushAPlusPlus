# RushAPlusPlus
A video recommending project

Used Data Structures and Algorithms:
1. Disjoint-set Data Structure
2. Graph Data Structure
3. PageRank Algorithm
4. Similar Users and Collaborative Filtering

Collaborators:
1. pg22 Brian Guo
2. weijia4 Weijia Zhang
3. ou14 William Ou
4. jiex5 Cici Xiong
5. yanyilu2 Yanyi Lu

## Leading Question 
**We want to find a non-AI way of ***recommending videos*** to ***different kind of users*** following the procedure below:**  
In our database, assume we have some initial videos and users, and we preserve the record of video **sequence** each user visited.   
We build labels for these videos using the idea of **disjoint set**, assume users like to watch travelling to China videos after visiting travelling to Japan, or travelling to US videos, we naturally use disjoint set to group them up and argue that they are the same label.   
For new users, we first use **PageRank** algorithm to recommend videos most users found important. This can be done as we preserve all visiting paths. And we will update the PageRank algorithm every time a new visiting record occurs.  
As the user explores more and more videos, we gradually add the weight of **Collaborative Filtering** algorithm which utilizes **User Similarity**, also to be implemented by us to recommend similar videos users with similar interest watches.  
We then **quicksorts** the rating generated by two algorithms times their weightings respectively according to how many vidoes a user has watched, to generate the final videolist recommending to a user at time *t*.  
Throughout the process, we might randomly add some unwatched and **away-from-users-interest** (which means the user may have never watched a certain label's videos) to the recommending list which allows the user to change his/her mind of interesting area, this as well allows we to generate labels for newly added videos.
## Major Deliverables
1. build big dataframe base on real world data.
2. Use disjoint set and cluster algorithms create labels videos and users.
3. Utilizing pagerank to calculate the scope.
4. Use colaborative filtering to get the appropiate recommendation video.
5. Use quick sort in visualization of the project. Make a iteractive model for the user to click the video.


## Dataset Acquisition and Processing
Mainly generated meaningfully by crew members.  
In the future use YouTube / Bilibili / other streaming platform public datas.

## Algorithms and Data Structures
1. Disjoint Set for Clustering
2. PageRank
3. User Similarity & Collaborative Filtering
4. Quick Sort
5. Randomseed Generation

## Timeline
Week 1 Clean dataset and build video & user class. Learn about different algorithms.   
Week 2 Finish indiviaul algorithms.   
Week 3 Integrating difference algorithms together.  
Week 4 Test and Debugging.  
Week 5 Beautify UI and prepare presentation.

## Github Repo
https://github.com/ETwilight/RushAPlusPlus
