#include "mu_test.h"
#include "block_queue.hpp"
#include "mutex.hpp"
#include "thread.hpp"
#include <pthread.h>

BEGIN_TEST(block_queue_test)
	using namespace mt;
    using namespace cpp;
    BlockQueue<int>(10);
    Thread td1(0, enqueue<int>, 0);

    ASSERT_PASS();
END_TEST



BEGIN_SUITE(不耻下问 this is a description)
 	
 	TEST(block_queue_test)


END_SUITE
