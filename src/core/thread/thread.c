
/**
 * @file /magma/core/thread/thread.c
 *
 * @brief	Functions for spawning new threads, and retrieving their exit statuses.
 */

#include "../core.h"

/**
 * @brief	Get the id of the calling thread.
 * @return	the id of the calling thread.
 */
pthread_t thread_get_thread_id(void) {

	return pthread_self();
}

/**
 * @brief	Launch a thread to execute a specified function.
 * @see		pthread_create()
 * @param	thread		a pointer to a pthread object to receive the new thread id.
 * @param	function	a pointer to a function to be executed inside the new thread.
 * @param	data		a pointer to be data to be passed in as input to the called function.
 * @return	0 on success, or a non-zero error code on failure.
 */
int_t thread_launch(pthread_t *thread, void *function, void *data) {

	int_t result;
	pthread_attr_t attributes;

	if ((result = pthread_attr_init(&attributes))) {
		mclog_pedantic("Could not initialize the thread attribute structure. {pthread_attr_init = %i}", result);
		return result;
	}
	else if ((result = pthread_attr_setstacksize(&attributes, magma_core.system.thread_stack_size))) {
		mclog_pedantic("Could not set the stack size correctly. {pthread_attr_setstacksize = %i}", result);
		pthread_attr_destroy(&attributes);
		return result;
	}
	else if ((result = pthread_create(thread, &attributes, function, data))) {
		mclog_pedantic("Could not initialize a new thread. {pthread_create = %i}", result);
		pthread_attr_destroy(&attributes);
		return result;
	}

	pthread_attr_destroy(&attributes);
	return result;
}

/**
 * @brief	Launch a function in a freshly created thread.
 * @see		pthread_create_new()
 * @param	function	a pointer to the function to be executed.
 * @param	data		a pointer to data to be passed to the executed function.
 * @return	NULL on failure, or a pointer to the newly created pthread on success.
 */
pthread_t * thread_alloc(void *function, void *data) {

	int_t ret;
	pthread_t *result;

	if (!(result = mm_alloc(sizeof(pthread_t)))) {
		mclog_pedantic("Could not allocate %zu bytes to hold the pthread_t structure.", sizeof(pthread_t));
		return NULL;
	}
	else if ((ret = thread_launch(result, function, data))) {
		mclog_pedantic("An error occurred while attempting to spawn the thread. {thread_init = %i}", ret);
		mm_free(result);
		return NULL;
	}

	return result;
}

/**
 * @brief	Block until a specified thread finishes execution.
 * @note	pthread_join()
 * @param	thread	the thread to wait upon.
 * @return	0 on success, or an error number on failure.
 */
int_t thread_join(pthread_t thread) {

	int_t ret = pthread_join(thread, NULL);

	if (ret) {
		mclog_pedantic("Could not join to the requested thread. { pthread_join = %i }", ret);
	}

	return ret;
}

/**
 * @brief	Block until a specified thread finishes execution and store its exit value.
 * @note	pthread_join()
 * @param	thread	the thread to wait upon.
 * @param	result	a pointer to a block of memory to receive the target thread exit value.
 * @return	0 on success, or an error number on failure.
 */
int_t thread_result(pthread_t thread, void **result) {

	int_t ret = pthread_join(thread, result);

	if (ret) {
		mclog_pedantic("Could not join to the requested thread. { pthread_join = %i }", ret);
	}

	return ret;
}

/**
 * @brief	Send a specified signal to a thread.
 * @param	thread	the target thread id.
 * @param	signal	the number of the signal to be delivered.
 * @return	0 on success or an error number on failure.
 */
int_t thread_signal(pthread_t thread, int_t signal) {

	return pthread_kill(thread, signal);
}

/**
 * @brief	Send a cancellation request to a thread.
 * @param	thread	the pthread id of the thread to be cancele.d.
 * @return	0 on success or a non-zero error number on failure.
 */
int_t thread_cancel(pthread_t thread) {

#ifdef MAGMA_PEDANTIC
	int_t result = pthread_cancel(thread);

	// ESRCH is returned if the thread has already exited, so we don't need to log any error message.
	if (result && result != ESRCH) {
		mclog_pedantic("Could not cancel the requested thread. {pthread_cancel = %i}", result);
	}

	return result;

#else
	return pthread_cancel(thread);
#endif

}

/**
 * @brief	Set the calling thread to be cancelable.
 * @return	This function returns no value.
 */
void thread_cancel_enable(void) {
	pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
	return;
}

/**
 * @brief	Set the calling thread to be not cancelable.
 * @return	This function returns no value.
 */
void thread_cancel_disable(void) {
	pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
	return;
}
