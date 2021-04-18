CREATE DATABASE IF NOT EXISTS `epytodo`;

USE `epytodo`;

DROP TABLE IF EXISTS `task`;
CREATE TABLE `task` (
  `task_id` int unsigned NOT NULL AUTO_INCREMENT,
  `title` varchar(128) NOT NULL,
  `begin` datetime DEFAULT CURRENT_TIMESTAMP,
  `end` datetime DEFAULT NULL,
  `status` enum('not started','in progress','done') DEFAULT 'not started',
  PRIMARY KEY (`task_id`)
);

DROP TABLE IF EXISTS `user`;
CREATE TABLE `user` (
  `user_id` int unsigned NOT NULL AUTO_INCREMENT,
  `username` varchar(128) NOT NULL,
  `password` char(128) NOT NULL,
  `sessionID` varchar(64) DEFAULT NULL,
  `data` json DEFAULT NULL,
  PRIMARY KEY (`user_id`),
  UNIQUE KEY `user_username_uindex` (`username`),
  UNIQUE KEY `user_sessionID_uindex` (`sessionID`)
);

DROP TABLE IF EXISTS `user_has_task`;
CREATE TABLE `user_has_task` (
  `fk_user_id` int unsigned DEFAULT NULL,
  `fk_task_id` int unsigned DEFAULT NULL,
  KEY `fk_task_id` (`fk_task_id`),
  KEY `fk_user_id` (`fk_user_id`),
  CONSTRAINT `fk_task_id` FOREIGN KEY (`fk_task_id`) REFERENCES `task` (`task_id`) ON DELETE CASCADE,
  CONSTRAINT `fk_user_id` FOREIGN KEY (`fk_user_id`) REFERENCES `user` (`user_id`) ON DELETE CASCADE
);