package com.harshraj22.application.services;

import com.harshraj22.application.models.Group;
import com.harshraj22.application.models.Profile;
import com.harshraj22.application.models.User;
import lombok.extern.slf4j.Slf4j;

@Slf4j
public class EntityManagementService {

    public Profile createProfile(String name) {
        log.info("Creating profile with name {}", name);

        // ToDo: Implement logic to create a profile
        return new Profile(name);
    }

    public User createUser(User user) {
        // ToDo: Implement logic to create a user

        return user;
    }

    public Group createGroup(Group group) {
        log.info("Creating group with name {}", group.getName());
        // ToDo: Implement logic to create a group

        return group;
    }

}
