# https://www.lintcode.com/problem/1786/

'''
Definition of PushNotification
class PushNotification:
    @classmethod
    def notify(user_id, message):
'''
class PubSubPattern:
    import collections 

    def __init__(self):
    # do intialization if necessary 
        self.users = collections.defaultdict(lambda: set())
        
    """
    @param: channel: a channel name
    @param: user_id: a user id
    @return: nothing
    """
    def subscribe(self, channel, user_id):
        # write your code here
        self.users[channel].add(user_id)

    """
    @param: channel: a channel name
    @param: user_id: a user id
    @return: nothing
    """

    def unsubscribe(self, channel, user_id):
    	# write your code here
        self.users[channel].discard(user_id)
        
    """
    @param: channel: a channel name
    @param: message: need send message
    @return: nothing
    """

    def publish(self, channel, message):
		# write your code here
        for user_id in self.users[channel]:
            PushNotification.notify(user_id, message)