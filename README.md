# BehaviorTree.ROS2
[![Test](https://github.com/BehaviorTree/BehaviorTree.ROS2/actions/workflows/test.yml/badge.svg)](https://github.com/BehaviorTree/BehaviorTree.ROS2/actions/workflows/test.yml)

This repository contains useful wrappers to use ROS2 and BehaviorTree.CPP together.

In particular, it provides a standard way to implement:

- Behavior Tree Executor with ROS Action interface.
- Action clients.
- Service Clients.
- Topic Subscribers.
- Topic Publishers.

Our main goals are:

- to minimize the amount of boilerplate.
- to make asynchronous Actions non-blocking.

# Documentation

- [ROS Behavior Wrappers](behaviortree_ros2/ros_behavior_wrappers.md)
- [TreeExecutionServer](behaviortree_ros2/tree_execution_server.md)
- [Sample Behaviors](btcpp_ros2_samples/README.md)

Note that this library is compatible **only** with:

- **BT.CPP** 4.6 or newer.
- **ROS2** Humble or newer.

Additionally, check **plugins.hpp** to see how to learn how to
wrap your Nodes into plugins that can be loaded at run-time.

# Installation

1. Download necessary repositories
```bash
~/ros_ws/src$ git clone https://github.com/marco-ambrosio/BehaviorTree.ROS2.git
~/ros_ws/src$ vcs import < BehaviorTree.ROS2/requirements.repos BehaviorTree.ROS2
```
2. Install dependencies with rosdep
```bash
~/ros_ws$ sudo apt update && rosdep update
~/ros_ws$ rosdep install --from-path src --ignore-src -y
```
3. Build the workspace


## Acknowledgements

A lot of code is either inspired or copied from [Nav2](https://docs.nav2.org/).

For this reason, we retain the same license and copyright.
