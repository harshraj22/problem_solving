
**Flip-Cache**

As an aspiring flipster you are asked to design a cache library ‘flip-cache’ using the basic data structures. Flip-Cache will be used by other components and applications (similar to any open source library you can download and use) Requirements are:

Cache should be bounded in the number of keys.
Design it in a way so that it is easy to add the following to the library
*     time bound eviction policy - which decides how to evacuate old data to make room for new data based on time.
*     data bound eviction policy - which decides how to evacuate old data to make room for new data based on new data.
*     Data store - where it keeps key-value pairs.
Users of the cache should be able to specify data store & eviction policy at initialization.
Provide one implementation of data store and eviction strategy.
(Bonus) It should be possible to get metrics around eviction strategy. One such metric possible is the hit ratio defined as: Number of key references that hit in the cache / total number of memory references.

**How you will be evaluated**
*     Code completeness
*     Separation of concerns
*     Abstractions
*     Application of OO design principles
*     Testability
*     Code readability
*     Language proficiency
