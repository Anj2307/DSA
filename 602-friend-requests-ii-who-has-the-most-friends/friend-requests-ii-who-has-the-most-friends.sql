
SELECT id, count(*) as num
FROM (
    SELECT requester_id AS id
    FROM RequestAccepted

    UNION ALL

    SELECT accepter_id AS id
    FROM RequestAccepted
) AS friends
group by id
order by num desc
limit 1 offset 0;
