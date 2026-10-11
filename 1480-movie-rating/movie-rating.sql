# Write your MySQL query statement below
(select u.name as results
from MovieRating as m
left join Users as u
on u.user_id=m.user_id
group by m.user_id
order by count(m.movie_id) desc, u.name asc
limit 1)
union all
(
    select mo.title as results
    from MovieRating as m
    left join Movies as mo
    on mo.movie_id=m.movie_id
    where date_format(created_at,'%Y-%m')="2020-02"
    group by mo.movie_id
    order by avg(m.rating) desc, mo.title
    limit 1 
);

