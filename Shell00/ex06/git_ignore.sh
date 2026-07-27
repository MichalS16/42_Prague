#!/bin/bash
git status --ignored --porcelain | grep '^!!' | cut -c4-
