#pragma once

#include <sys/types.h>
#include "demo.h"

enum {
	READ = 1,
	WRITE,
};

typedef unsigned long sector_t;

struct block_device {
	int fd;
	const char *name;
	const char *map;
	struct list_node bdev_node;
};

struct bio {
	void     *data;
	size_t   size;
	sector_t sect;
	struct block_device *bdev;
	unsigned long flags;
};

void *zalloc(size_t sz);

struct bio *bio_alloc();

void bio_free(struct bio *bio);

void submit_bio(int rw,struct bio * bio);

int block_device_register(struct block_device *bdev);

struct block_device *bdev_get(const char *name);