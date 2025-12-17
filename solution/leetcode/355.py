# https://leetcode.com/problems/design-twitter


import heapq
from typing import Dict
from typing import NamedTuple
from typing import List
import heapq

class Tweet(NamedTuple):
    id: int
    created_at: int

class User:
  def __init__(self, userId: int):
    self.id: int = userId
    self.follws: Dict[int, User] = dict()
    self.tweets: List[Tweet] = []

  def getTweetsIterator(self):
    yield from self.tweets[-1::-1]
  
  def postTweet(self, tweet: Tweet):
    self.tweets.append(tweet)

  def follow(self, user):
    self.follws[user.id] = user

  def unfollow(self, user):
    self.follws.pop(user.id, None)

class Timer:
  def __init__(self, initial_time: int = 0, increment_duration: int = 1):
    self.time = initial_time
    self.increment_duration = increment_duration

  def increment(self):
    self.time += self.increment_duration
  
  def get(self):
    return self.time
  

class Twitter:

    def __init__(self):
        self.users: Dict[int, User] = dict()
        self.timer = Timer()

    def getOrCreate(self, userId: int):
      if userId not in self.users:
        self.users[userId] = User(userId)
      return self.users[userId]

    def postTweet(self, userId: int, tweetId: int) -> None:
        tweet = Tweet(tweetId, self.timer.get())
        user = self.getOrCreate(userId)
        user.postTweet(tweet)
        self.timer.increment()

    def getNewsFeed(self, userId: int) -> List[int]:
        heap = []
        user = self.getOrCreate(userId)
        newsFeed = []

        for followee in [user, *user.follws.values()]:
          if not followee.tweets:
            continue
          tweetIterator = followee.getTweetsIterator()
          tweet = next(tweetIterator)
          heap.append((-tweet.created_at, tweet.id, tweetIterator))
        
        heapq.heapify(heap)
        while heap and len(newsFeed) < 10:
          item = heapq.heappop(heap)
          newsFeed.append(item[1])
          print(f'Popped item: {item}')
          try:
            tweetIterator = item[-1]
            tweet = next(tweetIterator)
            heapq.heappush(heap, (-tweet.created_at, tweet.id, tweetIterator))
          except StopIteration:
            pass
        
        return newsFeed

    def follow(self, followerId: int, followeeId: int) -> None:
        follower = self.getOrCreate(followerId)
        followee = self.getOrCreate(followeeId)
        follower.follow(followee)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        follower = self.getOrCreate(followerId)
        followee = self.getOrCreate(followeeId)
        follower.unfollow(followee)




# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)
