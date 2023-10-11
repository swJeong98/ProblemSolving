select t.writer_id, t.nickname, t.total
from (select b.writer_id, u.nickname, sum(b.price) as total 
      from used_goods_board b join used_goods_user u on b.writer_id = u.user_id
      where b.status = 'DONE'
      group by b.writer_id) as t 
where t.total >= 700000
order by t.total
