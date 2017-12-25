#include "../lab4-queue/TQueue.h"
#include "../test/gtest.h"

#include "gtest.h"

TEST(TQueue, can_create_queue_with_positive_length)
{
  ASSERT_NO_THROW(TQueue <int>(5));

}

TEST(TQueue, throw_when_create_queue_with_negative_length)
{
  ASSERT_ANY_THROW(TQueue <int>(-2));
}

/*TEST(TQueue, can_copy_queue)
{
    TQueue <int> q1;
    q1.push(5);

    ASSERT_NO_THROW(TQueue <int> q2(q1));
}*/

TEST(TQueue, can_check_if_queue_is_empty)
{
    TQueue <int> q;
    q.push(3);

    EXPECT_EQ(false, q.isempty());
}

TEST(TQueue, can_check_if_queue_is_not_empty)
{
    TQueue <int> q;

    EXPECT_NE(false, q.isempty());
}

TEST(TQueue, can_check_if_queue_is_full)
{
    TQueue <int> q(1);
    q.push(5);

    EXPECT_EQ(true, q.isfull());
}

TEST(TQueue, can_check_if_queue_is_not_full)
{
    TQueue <int> q(3);
    q.push(2);

    EXPECT_NE(true, q.isfull());
}

TEST(TQueue, cant_push_elem_in_full_queue)
{
    TQueue <int> q(1);
    q.push(1);

    ASSERT_ANY_THROW(q.push(8));
}

TEST(TQueue, cant_take_elem_from_empty_stack)
{
    TQueue <int> q;


    ASSERT_ANY_THROW(q.pop());
}
TEST(TQueue, can_put_elem_in_not_empty_stack)
{
    TQueue <int> q;
    q.push(7);

    ASSERT_NO_THROW(q.pop());
}