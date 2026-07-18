# Write your MySQL query statement below
SELECT tweet_id 
From Tweets
Where CHAR_LENGTH(content)>15;