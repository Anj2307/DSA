# Write your MySQL query statement below
select c1.visited_on, sum(c2.amount) as amount, round(sum(c2.amount)/7,2) as average_amount
from (
    select visited_on, sum(amount) as amount
    from Customer
    group by visited_on
)c1
join
(
    select visited_on,sum(amount) as amount
    from Customer
    group by visited_on
)c2
on datediff(c1.visited_on,c2.visited_on) between 0 and 6
group by c1.visited_on
having datediff(visited_on,(select min(visited_on) from Customer))>=6
order by visited_on;